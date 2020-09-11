cmake_minimum_required(VERSION 3.0.2)
project(hw1)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(final src/final.cpp)
target_link_libraries(final ${catkin_LIBRARIES})
