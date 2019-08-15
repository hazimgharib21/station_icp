#include "ros/ros.h"
#include <vector>
#include <iostream>
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan_in){

  ROS_INFO("Scan Data Received");
  std::vector<float> range = scan_in->ranges;

}

void mapLayoutCallback(const std_msgs::String::ConstPtr& msg){

  ROS_INFO("Map Layout Data Received");
  std::string map_str = msg->data;

}

int main(int argc, char **argv){

  ros::init(argc, argv, "station_icp");
  ros::NodeHandle n;
  ros::Rate loop_rate(10);

  ros::Subscriber scan_sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 10, scanCallback);
  ros::Subscriber mapLayout_sub = n.subscribe<std_msgs::String>("/map_layout", 10, mapLayoutCallback);

  while(ros::ok()){

    ros::spinOnce();

    loop_rate.sleep();
  
  }

  return 0;

}
