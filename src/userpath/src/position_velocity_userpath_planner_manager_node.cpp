#include <fastrack/state/position_velocity.h>
#include <userpath/userpath_planner_manager.h>

namespace up = userpath;
namespace fs = fastrack::state;

int main(int argc, char** argv) {
  ros::init(argc, argv, "UserpointPlannerManager");
  ros::NodeHandle n("~");

  up::UserpathPlannerManager<fs::PositionVelocity> manager;

  if (!manager.Initialize(n)) {
    ROS_ERROR("%s: Failed to initialize planner manager.",
              ros::this_node::getName().c_str());
    return EXIT_FAILURE;
  }

  ros::spin();

  return EXIT_SUCCESS;
}
