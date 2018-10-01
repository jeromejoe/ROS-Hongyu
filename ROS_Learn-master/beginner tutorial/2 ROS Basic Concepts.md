## This document shows how to build up basic concepts as a beginner

### This is the link to the [official tutorial](http://wiki.ros.org/ROS/Tutorials/) . Please go through beginner level section.

### [*A Gentle Introduction to ROS*](https://cse.sc.edu/~jokane/agitr/ ) is a good book for beginners, which is free online. 
Please go through Chapter 1,2,3,6,8 which consists important concepts and useful examples.

### Brief summary of the key concepts
1. How to create a **catkin workspace**
2. What makes up a catkin **package**
``` bash
    my_package/
      CMakeLists.txt
      package.xml
```
3. Package and workspace
``` bash
    workspace_folder/        -- WORKSPACE
      src/                   -- SOURCE SPACE
        CMakeLists.txt       -- 'Toplevel' CMake file, provided by catkin
        package_1/
          CMakeLists.txt     -- CMakeLists.txt file for package_1
          package.xml        -- Package manifest for package_1
          ...
        package_n/
          CMakeLists.txt     -- CMakeLists.txt file for package_n
          package.xml        -- Package manifest for package_n
```
4. Package dependency
5. **Nodes**: A node is an executable that uses ROS to communicate with other nodes.
  * rosrun [package] [node]
6. **Messages**: ROS data type used when subscribing or publishing to a topic.
  * rosmsg show [message]
7. **Topics**: Nodes can publish messages to a topic as well as subscribe to a topic to receive messages.
  * rostopic echo [topic]
  * rostopic list
  * rostopic type [topic]
  * rostopic pub [topic] [msg_type] [args]
8. Using **rqt_graph** to identify topics, messages, etc
9. **Services**: Services are another way that nodes can communicate with each other. Services allow nodes to send a request and receive a response.
  * rosservice list
  * rosservice type [service]
  * rosservice call [service] [args]
  * rosparam get [param_name]
  * rosparam set [param_name] [param_value]
10. Using **ROS launch**
  * roslaunch [package] [filename.launch]
11. **Publisher**: Publisher can publish message to a topic, how to write a publisher is important.
12. **Subscriber**: Subscriber can receive message from a topic, how to write a subscriber is important <br>
  Steps of how to create a publisher/subscriber    <br>
``` bash
    1 write the source code in package/src  
    2 modify the CMakelist.txt of the package
    3 make the excecutable file
    4 catkin_make
    5 rosrun 
```
  This [link](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29) shows how to create a publisher and a subscriber
