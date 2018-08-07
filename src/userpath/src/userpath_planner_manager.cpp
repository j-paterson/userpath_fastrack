#include <userpath/userpath_planner_manager.h>

namespace userpath{

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

  return true;
}

// Callback to handle new userpoint instructions
// Has different behavior depending on the action sent
template<typename S>
void UserpathPlannerManager<S>::UserpointCallback(const userpath_msgs::UserpointInstruction::ConstPtr& msg) {

  ROS_INFO("Received a UserpointInstruction");

  if(msg->action=="ADD"){
    // ADD
    Userpoint * new_point = new Userpoint(msg->curr_id, Vector3d(msg->x, msg->y, msg->z));
    userpoints.insert(std::pair<std::string, Userpoint*>(msg->curr_id, new_point));

    // If there is a path, we traverse to the end.
    // Otherwise we just set this point as the first one on the path.
    if(current_point.id!=""){
      Userpoint * last_point = &current_point;

      while (last_point->next!=0){
          last_point = last_point->next;
      }

      last_point->next = new_point;
      new_point->prev = last_point;
      ROS_INFO("Adding to the end of the path");

    } else {
      current_point = *new_point;
      ROS_INFO("Creating new waypoint");
    }

    reached_goal_ = false;
  } else if (msg->action=="DELETE"){
  // DELETE
    Userpoint * delete_point = userpoints[msg->curr_id];
    Userpoint * next_point = delete_point->next;
    Userpoint * prev_point = delete_point->prev;

    prev_point->next = next_point;
    next_point->prev = prev_point;

    // Check if we deleted the goal.
    if(delete_point->id == current_point.id){
      //Trigger a remapping
      current_point = *current_point.next;
      trigger_replan_pub_.publish(std_msgs::Empty());
    }

  } else if(msg->action=="INSERT"){
    // INSERT
    Userpoint * new_point = new Userpoint(msg->curr_id, Vector3d(msg->x, msg->y, msg->z));
    userpoints.insert(std::pair<std::string, Userpoint*>(msg->curr_id, new_point));

    Userpoint * prev_point = userpoints[msg->prev_id];
    Userpoint * next_point = prev_point->next;

    prev_point->next = new_point;
    next_point->prev = new_point;

    new_point->prev = prev_point;
    new_point->next = next_point;

    // Check if we are inserting along the currently planned trajectory.
    if(next_point->id == current_point.id){
      //Trigger a remapping
      current_point = *new_point;
      trigger_replan_pub_.publish(std_msgs::Empty());
    }

  } else if(msg->action=="MODIFY"){
    Userpoint * modify_point = userpoints[msg->curr_id];
    modify_point->location = Vector3d(msg->x, msg->y, msg->z);
    
    // Check if the point we are modifying is the goal.
    if(modify_point->id == current_point.id){
      // Trigger a remapping
      trigger_replan_pub_.publish(std_msgs::Empty());
    }
  }
}

// If not already waiting, request a new trajectory that starts along the
// current trajectory at the state corresponding to when the planner will
// return, and ends at the goal location. This may be overridden by derived
// classes with more specific replanning needs.
template<typename S>
void UserpathPlannerManager<S>::MaybeRequestTrajectory() {
  if (!ready_ || waiting_for_traj_)
    return;

  // Set start and goal states.
  fastrack_msgs::ReplanRequest msg;
  msg.start = current_point.location;
  msg.goal = current_point.next.location;

  current_point=*current_point.next;

  // Set start time.
  msg.start_time = ros::Time::now().toSec() + planner_runtime_;

  // Reset start state for future state if we have a current trajectory.
  if (traj_.Size() > 0) {
    // Catch trajectory that's too short.
    if (traj_.LastTime() < msg.start_time) {
      ROS_ERROR("%s: Current trajectory is too short. Cannot interpolate.",
                name_.c_str());
      msg.start = traj_.LastState().ToRos();
    } else {
      msg.start = traj_.Interpolate(msg.start_time).ToRos();
    }
  }

  // Publish request and set flag.
  replan_request_pub_.publish(msg);
  waiting_for_traj_ = true;
}

} //\namespace userpath
