#!/usr/bin/env python

import rospy
import json
from std_msgs.msg import String
from sensor_msgs.msg import LaserScan

stations = list()

def scanCallback(data):
    pass
    #rospy.loginfo("Get Scan Data")

def mapLayoutCallback(data):

    map_json = json.loads(data.data)
    

    for item in map_json:
        print(str(item))

    print("Paths---------------------")
    for item in map_json["paths"]:
        print(str(item["cp1"]) + " " + str(item["cp2"]))

    print("\nJunction Count----------------")
    print(map_json["junction_count"])

    print("\nJunctionssss----------------")
    for item in map_json["junctions"]:
        print(str(item))

    print("\nStations---------------------")
    for item in map_json["stations"]:
        stations.append(item["name"])

    for station in stations:
        print(station)

def station_icp():
    
    rospy.init_node('station_icp', anonymous=False)
    rospy.Subscriber("/scan", LaserScan, scanCallback)
    rospy.Subscriber("/map_layout", String, mapLayoutCallback)
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        rate.sleep()

if __name__ == '__main__':
    try:
        station_icp()
    except rospy.ROSInterruptException:
        pass

