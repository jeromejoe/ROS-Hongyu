// This program subsceribes to turtle1/posse and shows its messages on the screen

#include<ros/ros.h>
#include<gazebo_msgs/ModelStates.h>
#include<iomanip> //For std::setprecision and std::fixed

// A callback function. Executed each time a new pose message arrives

void poseMessageReceived(const gazebo_msgs::ModelStates& msg){ROS_INFO_STREAM(std::setprecision(2) << std::fixed <<"position= (" << msg.quadrotor.pose.linear.x);}
//Type: gazebo_msgs/ModelStates
//Topic: gazebo/model_states
int main(int argc, char **argv)
{

//Initialize the ROS system and become a node
ros::init(argc, argv, "subscribe_to_pose");
ros::NodeHandle nh;

//Create a subscriber object
ros::Subscriber sub = nh.subscribe("gazebo/model_states", 1000, &poseMessageReceived);

//Let ROS takeover
ros::spin();

}
