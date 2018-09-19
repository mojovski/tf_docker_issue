#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <turtlesim/Spawn.h>
#include <geometry_msgs/Twist.h>


//from here: https://github.com/jack-oquin/bwi_learn_tf/blob/master/src/turtle_tf_listener.cpp

int main(int argc, char** argv){
  ROS_INFO("Starting test179 node");
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  ROS_INFO_STREAM("New node ok?: " << node.ok());

  tf::TransformListener listener;

  ros::Rate rate(1.0);

  while (node.ok()){
    tf::StampedTransform transform;
    std::string err_msg;
    ROS_INFO("Trying to wait for transform");
    std::string global_frame="map";
    std::string robot_frame="base_link";
    try{
      ROS_INFO_STREAM("timenow: " << ros::Time::now().toSec());
      bool res=listener.waitForTransform(global_frame, robot_frame,
                               ros::Time::now(), ros::Duration(0.1), ros::Duration(0.1),
                               &err_msg);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
    }

    rate.sleep();
  }
  return 0;
};
