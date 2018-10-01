## We are going to use tum_simulator as our platform, this document shows how to setup the environment

### Installation (ros-indigo version)
Package required: <br>
* [tum_simulator](http://wiki.ros.org/tum_simulator)
* [ardrone_autonomy](https://github.com/tum-vision/ardrone_autonomy)
* [tum_ardrone](https://github.com/tum-vision/tum_ardrone)
* gazebo
* rviz

#### tum_simulator installation

1. Create a workspace for the simulator 
``` bash
mkdir -p ~/tum_simulator_ws/src 
cd  ~/tum_simulator_ws/src 
catkin_init_workspace
```
2. Download dependencies  
``` bash
git clone https://github.com/AutonomyLab/ardrone_autonomy.git	# The AR.Drone ROS driver 
git clone https://github.com/occomco/tum_simulator.git 
cd .. 
rosdep install --from-paths src --ignore-src --rosdistro indigo -y 
```
3. Build the simulator <br>
``` bash
catkin_make
```
4. Source the environment <br>
``` bash
source devel/setup.bash 
```

#### ardrone_autonomy installation
``` bash
mkdir -p ~/ardrone_autonomy_ws/src
cd  ~/ardrone_autonomy_ws/src

catkin_init_workspace
git clone https://github.com/AutonomyLab/ardrone_autonomy.git -b indigo-devel
cd ~/ardrone_autonomy_ws
rosdep install --from-paths src -i
catkin_make
```

#### tum_ardrone installation
``` bash
cd ardrone_autonomy_ws/src
git clone https://github.com/tum-vision/tum_ardrone.git -b indigo-devel
cd ..
rosdep install tum_ardrone
catkin_make
```
#### Notice
tum_ardrone and tum_autonomy should be installed in the **same** catkin workspace

### Test your simulator
1. tum_simulator
``` bash
cd  ~/tum_simulator_ws       #switch workspace
source devel/setup.bash       #source
roslaunch cvg_sim_gazebo ardrone_testworld.launch       #open gazebo testworld
```
2. tum_ardrone
``` bash
cd  ~/tum_ardrone_ws       #switch workspace
source devel/setup.bash       #source
roslaunch tum_ardrone tum_ardrone.launch      #launch the controller
```
3. keyboard control  <br>
``` bash 
Enable keyboard control in the GUI, first "take off" the quadcopter and control it with the following commands 
• q,a: fly up & down.
• i,j,k,l: fly horizontally.
• u,o: rotate yaw.
• F1: toggle emergency
• s: takeoff
• d: land
```

4. test camera and sensors
``` bash
# The front camera
rosrun image_view image_view image:=/ardrone/front/image_raw
# The buttom camera
rosrun image_view image_view image:=/ardrone/bottom/image_raw
# The height sensor
rostopic echo /sonar_height
#The navigation info
rostopic echo /ardrone/navdata
```
