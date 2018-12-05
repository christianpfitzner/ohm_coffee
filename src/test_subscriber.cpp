#include "ros/ros.h"
#include "std_msgs/String.h"

void androidIDCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("Android ID: [%s]", msg->data.c_str());
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "Subscriber");
	ros::NodeHandle nhServer;
	ros::Subscriber sub = nhServer.subscribe("Android", 1, androidIDCallback);
ros::spin(); 

//return 0;
}

