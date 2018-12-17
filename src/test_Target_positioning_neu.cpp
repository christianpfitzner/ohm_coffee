#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/String.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <XmlRpcValue.h>



void androidIDCallback(const std_msgs::String::ConstPtr& msg)
{
	ros::NodeHandle prvNh("~");
	ros::NodeHandle nhServer;
	ros::Publisher targetPos;

	XmlRpc::XmlRpcValue param_list;
	geometry_msgs::PoseStamped Target;

	std::string name;
	std::string name_string;
	

	ROS_DEBUG("Android ID: [%s]", msg->data.c_str());
	
	name = msg->data;

	std::cout << name << std::endl;
	name_string = name;

	if (!prvNh.getParam(name_string, param_list)) 
	{
	ROS_ERROR("failed to get data - check ID!");
	}
	else{
	    ROS_INFO("param ok");
	    }

	std::cout << "testwert: " << param_list[0] << std::endl;

	Target.header.frame_id = "map";	
	Target.pose.position.x = param_list[0];
	Target.pose.position.y = param_list[1];
	Target.pose.orientation.w = param_list[2];

	targetPos = nhServer.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1);
	targetPos.publish(Target);

	ros::spin();
}






int main(int argc, char** argv)
{

	ros::init(argc, argv, "TargetPositionsNode");

	
	ros::NodeHandle nhServer;

	

	ros::Subscriber sub = nhServer.subscribe("Android", 1, androidIDCallback);

	

	//ros::spin();

	while(ros::ok())
	{
		ros::spinOnce();
	}

/*
	ros::Rate rate(10); 
	while(ros::ok())
	{
		targetPos.publish(Target);
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		ros::spinOnce(); 
		//rate.sleep(); 	
	}
*/		
}
