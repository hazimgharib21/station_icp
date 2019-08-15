#include "ros/ros.h"
#include <vector>
#include <iostream>
#include "sensor_msgs/LaserScan.h"

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan_in){

  ROS_INFO("Scan Data Received");
  std::vector<float> range = scan_in->ranges;
  std::cout << range << std::endl;

}

int main(int argc, char **argv){

  ros::init(argc, argv, "station_icp");
  ros::NodeHandle n;
  ros::Rate loop_rate(10);

  ros::Subscriber scan_sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 10, scanCallback);

  while(ros::ok()){

    ros::spinOnce();

    loop_rate.sleep();
  
  }

  return 0;

}
