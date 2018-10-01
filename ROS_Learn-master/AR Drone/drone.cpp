// This program publishes randomly generated velocity messages for tum_simulator.

#include<ros/ros.h>
#include<geometry_msgs/Twist.h>  //For geometry_msgs::Twist
#include<std_msgs/Empty.h>       //important!!
#include<stdlib.h> //For rand() and RAND_MAX

int main(int argc, char **argv)
{

//Initialize the ROS system and become a node.
ros::init(argc, argv, "publish_velocity1");
ros::NodeHandle nh;


//Create a publisher object
ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

//take off
ros::Publisher pub1 = nh.advertise<std_msgs::Empty>("/ardrone/takeoff", 5);
std_msgs::Empty msg1;




//Seed the random number generator
srand(time(0));

//Loop at 2Hz until the node is shut down
ros::Rate rate(2);
rate.sleep();        //if not sleep pub1 doesn't work
pub1.publish(msg1);

while(ros::ok())
{
//Create and fill in the message. The other four field, which are ignored by turtlesim, default to 0.
geometry_msgs::Twist msg;
msg.linear.x = double(rand())/double(RAND_MAX);
msg.angular.z = 2*double(rand())/double(RAND_MAX)-1;

//Publish the message.
pub.publish(msg);
//pub1.publish(msg1);
//Send a message to rosout with the details.
ROS_INFO_STREAM("Sending random velocity command:"<<" linear = "<<msg.linear.x <<" angular="<< msg.angular.z);

//Wait until it's time for another iteration
rate.sleep();
}

}
