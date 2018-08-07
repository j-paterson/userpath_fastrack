#ifndef USERPATH_USERPATH_PLANNER_MANAGER_H
#define USERPATH_USERPATH_PLANNER_MANAGER_H

#include <fastrack/planning/planner_manager.h>
#include <userpath/userpoint.h>
#include <userpath_msgs/UserpointInstruction.h>
#include <unordered_map>

using namespace fastrack;
using namespace planning;

namespace userpath{

template<typename S> 
class UserpathPlannerManager : public PlannerManager<S> {

protected:
  // Load parameters and register callbacks. These may be overridden, however
  // derived classes should still call these functions.
  bool LoadParameters(const ros::NodeHandle& n);
  bool RegisterCallbacks(const ros::NodeHandle& n);

  // Callback to handle new user inputed points.
  void UserpointCallback(const userpath_msgs::UserpointInstruction::ConstPtr& msg);
  
  // If not already waiting, request a new trajectory that starts along the
  // current trajectory at the state corresponding to when the planner will
  // return, and ends at the goal location. This may be overridden by derived
  // classes with more specific replanning needs.
  void MaybeRequestTrajectory();

  // Callback for applying tracking controller.
  void TimerCallback(const ros::TimerEvent& e);

  // Start/goal states.
  //fastrack_msgs::State start_;
  //fastrack_msgs::State goal_;

  // Collection of all userpoints in the userpath
  std::unordered_map<std::string, Userpoint*> userpoints;

  // The point currently being mapped to
  Userpoint current_point;

  // Publishers/subscribers
  ros::Subscriber userpoint_sub_;

  // Related topics
  std::string userpoint_topic_;

};

// IMPLEMENTATION
// The only portable way of using templates at the moment is to implement them in header files by using inline functions.

// Load parameters.
template<typename S>
bool UserpathPlannerManager<S>::LoadParameters(const ros::NodeHandle& n) {
  ros::NodeHandle nl(n);

  // Inherited parameters
  if (!PlannerManager<S>::LoadParameters(n)) return false;

  // Topics
  if (!nl.getParam("topic/userpoint", userpoint_topic_)) return false;  
  
  return true;
}

// Register callbacks.
template<typename S>
bool UserpathPlannerManager<S>::RegisterCallbacks(const ros::NodeHandle& n) {
  ros::NodeHandle nl(n);

  // Inherited callbacks
  if (!PlannerManager<S>::RegisterCallbacks(n)) return false;

  // Subscribers.
  userpoint_sub_ = nl.subscribe(
    userpoint_topic_.c_str(), 1, &UserpathPlannerManager::UserpointCallback, this);

  // Test Points

  //Userpoint * first_point = new Userpoint("1", std::vector<double>{1, 1, 1});
  //Userpoint * second_point = new Userpoint("2", std::vector<double>{1, 2, 1});
  //Userpoint * third_point = new Userpoint("3", std::vector<double>{1, 3, 1});

  //current_point = *first_point;
  //current_point.next = second_point;
  //second_point->next = third_point;

  return true;
}

// Callback to handle new userpoint instructions
// Has different behavior depending on the action sent
template<typename S>
void UserpathPlannerManager<S>::UserpointCallback(const userpath_msgs::UserpointInstruction::ConstPtr& msg) {

  ROS_INFO("Received a UserpointInstruction");

  if(msg->action=="ADD"){
    // ADD
    Userpoint * new_point = new Userpoint(msg->curr_id, std::vector<double>{msg->x, msg->y, msg->z});
    userpoints.insert(std::pair<std::string, Userpoint*>(msg->curr_id, new_point));

    // If there is a path, we traverse to the end.
    // Otherwise we just set this point as the first one on the path.
    if(current_point.id!=""){
      Userpoint * last_point = &current_point;

      while (last_point->next!=NULL){
          last_point = last_point->next;
      }

      last_point->next = new_point;
      new_point->prev = last_point;
      ROS_INFO("Adding to the end of the path");

    } else {
      current_point = *new_point;
      this->goal_.x = current_point.location;
      ROS_INFO("Creating first waypoint");
    }

  } else if (msg->action=="DELETE"){
  // DELETE
    Userpoint * delete_point = userpoints[msg->curr_id];
    Userpoint * next_point = delete_point->next;
    Userpoint * prev_point = delete_point->prev;

    if (prev_point!=NULL){
      prev_point->next = next_point;
    }

    next_point->prev = prev_point;

    // Check if we deleted the goal.
    if(delete_point->id == current_point.id){
      //Trigger a replan
      current_point = *current_point.next;
      this->goal_.x = current_point.location;
    }

  } else if(msg->action=="INSERT"){
    // INSERT
    Userpoint * new_point = new Userpoint(msg->curr_id, std::vector<double>{msg->x, msg->y, msg->z});
    userpoints.insert(std::pair<std::string, Userpoint*>(msg->curr_id, new_point));

    Userpoint * prev_point = userpoints[msg->prev_id];
    Userpoint * next_point = prev_point->next;

    prev_point->next = new_point;
    next_point->prev = new_point;

    new_point->prev = prev_point;
    new_point->next = next_point;

    // Check if we are inserting along the currently planned trajectory.
    if(next_point->id == current_point.id){
      //Trigger a replan
      current_point = *new_point;
      this->goal_.x = current_point.location;
    }

  } else if(msg->action=="MODIFY"){
    Userpoint * modify_point = userpoints[msg->curr_id];
    modify_point->location = std::vector<double>{msg->x, msg->y, msg->z};
    
    // Check if the point we are modifying is the goal.
    if(modify_point->id == current_point.id){
      // Trigger a replan
      this->goal_.x = current_point.location;
    }
  }
}

// If not already waiting, request a new trajectory that starts along the
// current trajectory at the state corresponding to when the planner will
// return, and ends at the goal location. This may be overridden by derived
// classes with more specific replanning needs.
template<typename S>
void UserpathPlannerManager<S>::MaybeRequestTrajectory() {
  if (!this->ready_ || this->waiting_for_traj_)
    return;

  ROS_INFO("Maybe Request Trajectory");

  // Set start and goal states.
  fastrack_msgs::ReplanRequest msg;
  msg.start = this->start_;
  msg.goal = this->goal_;

  // Set start time.
  msg.start_time = ros::Time::now().toSec() + this->planner_runtime_;

  // Reset start state for future state if we have a current trajectory.
  if (this->traj_.Size() > 0) {
    // Catch trajectory that's too short.
    if (this->traj_.LastTime() < msg.start_time) {
      ROS_ERROR("%s: Current trajectory is too short. Cannot interpolate.",
                this->name_.c_str());
      msg.start = this->traj_.LastState().ToRos();
    } else {
      msg.start = this->traj_.Interpolate(msg.start_time).ToRos();
    }
  }

  // Publish request and set flag.
  this->replan_request_pub_.publish(msg);
  this->waiting_for_traj_ = true;
}

template<typename S>
void UserpathPlannerManager<S>::TimerCallback(const ros::TimerEvent& e) {
  if (!this->ready_)
    return;

  if (this->traj_.Size() == 0) {
    MaybeRequestTrajectory();
    return;
  } else if (this->traj_.Size() == 0 && this->waiting_for_traj_) {
    ROS_WARN_THROTTLE(1.0, "%s: Waiting for trajectory.", this->name_.c_str());
    return;
  }

  // Interpolate the current trajectory.
  const S planner_x = this->traj_.Interpolate(ros::Time::now().toSec());

  // Convert to ROS msg and publish.
  this->ref_pub_.publish(planner_x.ToRos());

  // Broadcast transform.
  geometry_msgs::TransformStamped tf;
  tf.header.frame_id = this->fixed_frame_;
  tf.header.stamp = ros::Time::now();
  tf.child_frame_id = this->planner_frame_;

  tf.transform.translation.x = planner_x.X();
  tf.transform.translation.y = planner_x.Y();
  tf.transform.translation.z = planner_x.Z();
  tf.transform.rotation.x = 0;
  tf.transform.rotation.y = 0;
  tf.transform.rotation.z = 0;
  tf.transform.rotation.w = 1;

  this->tf_broadcaster_.sendTransform(tf);

  // Compare the current time to the end time of the planner. 
  // If the current time is past the end time, then we have reached the current goal and can update to the next userpoint
  if(this->traj_.LastTime() - ros::Time::now().toSec() < 0) {
    ROS_INFO_THROTTLE(1,"Reached Userpoint ID: %s", current_point.id.c_str());
    if(current_point.next != NULL){
      ROS_INFO_THROTTLE(1,"Moving to next point on the path");
      current_point = *current_point.next;
      this->goal_.x = current_point.location;
      MaybeRequestTrajectory();
    }
  }
}


} //\namespace userpath

#endif
