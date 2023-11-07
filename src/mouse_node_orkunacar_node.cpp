#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    ros::init(argc, argv, "mouse_node_orkunacar");
    ros::NodeHandle nh;
    ros::Publisher mouse_pub = nh.advertise<std_msgs::String>("/mouse_node", 1000);
    ros::Rate loop_rate(10); // Adjust the rate as needed

    std::ifstream mouse_file;
    mouse_file.open("/dev/input/mouse1", std::ios::binary);

    if (!mouse_file.is_open()) {
        ROS_ERROR_STREAM("Failed to open /dev/input/mouse1. Please check permissions.");
        return 1;
    }

    ROS_INFO("Starting to publish mouse events.");

    while (ros::ok()) {
        char buffer[3]; // A mouse event should be 3 bytes
        if (mouse_file.read(buffer, sizeof(buffer))) {
            // Convert the buffer to a string and publish it
            std::stringstream ss;
            ss << "Button: " << (int)buffer[0] << ", X: " << (int)buffer[1] << ", Y: " << (int)buffer[2];
            std_msgs::String msg;
            msg.data = ss.str();
            mouse_pub.publish(msg);
            ROS_INFO("%s", msg.data.c_str());
        } else {
            ROS_ERROR("Failed to read from /dev/input/mouse1");
            break;
        }
        ros::spinOnce();
        loop_rate.sleep();
    }

    mouse_file.close();
    return 0;
}

