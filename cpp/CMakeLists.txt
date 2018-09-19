# %Tag(FULLTEXT)%
cmake_minimum_required(VERSION 2.8.3)
project(test179)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy tf std_msgs)


## Declare ROS messages and services


## Generate added messages and services

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(test179 src/test_bug179.cpp)
target_link_libraries(test179 ${catkin_LIBRARIES})




# %EndTag(SRVCLIENT)%

# %EndTag(FULLTEXT)%
