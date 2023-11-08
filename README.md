# 🖱️ mouse_node_orkunacar

This ROS package 📦 is designed to read raw mouse events 🖱️ from the /dev/input/mouse0 device and publish the data to a ROS topic named /mouse_node.
Prerequisites 📋

Make sure you have ROS Noetic installed on Ubuntu 20.04 (or any compatible ROS distribution based on your operating system). Also, ensure that you have created a catkin workspace (catkin_ws).
## Installation 🔧

Clone this repository into the src directory of your catkin workspace:

    cd ~/catkin_ws/src
    mkdir mouse_node_orkunacar
    cd mouse_node_orkunacar
    git clone https://github.com/Orkun00/mouse_node_orkunacar.git

## Building the Package 🏗️
Before doing this step make sure you use source on your terminal. This step also given in running the ros node part.

To build the package, navigate to the root of your catkin workspace and run catkin_make:

    cd ~/catkin_ws
    catkin_make

This command will build all the packages in the workspace, including mouse_node_orkunacar. 

## Running the ROS Node 🚀

Before running the node, you must source the setup files:

    source /opt/ros/noetic/setup.bash 
or

    source ~/catkin_ws/devel/setup.bash

You can add these lines to your ~/.bashrc file to automatically source them in every new terminal:

    echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
    echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
    source ~/.bashrc

To run the node:

    rosrun mouse_node_orkunacar mouse_node_orkunacar_node

If you face permission issues with /dev/input/mouse0, you may need to run the node with sudo or change the device's permissions. Viewing the Published Data 📈

To see the published data on the /mouse_node topic:

    rostopic echo /mouse_node

This will display the mouse event data being published by the node.
## License 📜

MIT License
## Author ✍️

Orkun Acar - orkun.acar@ozu.edu.tr
