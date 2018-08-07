cmake_minimum_required(VERSION 2.8.3)
project(userpath)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/fastrack/modules)
message("Cmake module path: ${CMAKE_MODULE_PATH}")

find_package(Eigen3 REQUIRED)
find_package(ompl REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
  geometry_msgs
  std_msgs
  tf2_ros
  fastrack
  userpath_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
    visualization_msgs
    geometry_msgs
    std_msgs
    tf2_ros
    fastrack
    userpath_msgs
  DEPENDS
   EIGEN3
   OMPL
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
  ${OMPL_INCLUDE_DIRS}
  include
)

link_directories(
  ${catkin_LIBRARY_DIRS}
  ${EIGEN3_LIBRARY_DIRS}
  ${OMPL_LIBRARY_DIRS}
)

add_executable(position_velocity_userpath_planner_manager_node src/position_velocity_userpath_planner_manager_node.cpp)
target_link_libraries(position_velocity_userpath_planner_manager_node ${catkin_LIBRARIES})
add_dependencies(position_velocity_userpath_planner_manager_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
