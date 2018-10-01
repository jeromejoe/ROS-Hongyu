### Introduction
MATLAB is a handy tool to do calculation, therefore it is convenient to write scripts on MATLAB and use MATLAB toolbox to apply our algorithms to ROS. This document shows how to install Robotics System Toolbox, setup, and apply proportional control.

### Install Robotics System Toolbox
We are going to use MATLAB Robotics System Toolbox. 
This is the [link](https://www.mathworks.com/products/robotics.html?s_tid=srchtitle) to the webpage where you can try or buy the product.

### Setup Robotics System Toolbox
The full document of the toolbox is [here](https://www.mathworks.com/help/robotics/index.html). We only shows the simplest steps to do a quick setup.
#### Setup Two Computers(Master and Client)
First you need computer A(Ubuntu OS) as the ROS Master, on which you run the AR Drone simulator. Then you need computor B(Windows OS is ok) to run MATLAB. What we do is write scripts on B and connect A and B together by letting both computer connected to the same WiFi. Then it feels like we are using B to control A.
#### Connect to an External ROS Master
After you finished setting up computer A and B, and letting them have same network connection. You can do ROS initialization(connect A and B) on B.  
If you know the entire URI (Uniform Resource Identifier) of the master, you can create the global node and connect to this master using the following syntax:
```bash
rosinit('http://192.168.1.1:12000')
```
In our lab, the command is:
```bash
rosinit('http://128.200.3.67:11311')
```
You can find the host information with this command:
```bash
sudo gedit /etc/hosts
```

### Apply Proportional Control
First go through the toolbox [document](https://www.mathworks.com/help/robotics/index.html) and get familiar with how to use rospublisher/rossubscriber, how to create message, etc. <br>
I post the matlab code(ardrone_Proportional.m) in the same folder, it includes all details of how to apply proportional control to the gazebo simulation environment.
