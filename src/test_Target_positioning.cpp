#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include "std_msgs/String.h"

ros::Publisher targetPositions;

void androidIDCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("Android ID: [%s]", msg->data.c_str());
/*	
	if (ID == 123)
	{
	x = 
	y = 
	}

	if (ID == 456)
	{
	x = 
	y = 
	}

	if (ID == 789)
	{
	x = 
	y = 
	}
*/
	//targetPositions.publish(hier noch daten);
}






int main(int argc, char** argv)
{

	ros::init(argc, argv, "TargetPositionsNode");
	int var = 0;
	int ID = 0;


	ros::NodeHandle prvNh("~");

	// parameters position 1

	prvNh.param<int>("x1", var, 0);
	std::cout << " read position x1: " << var << std::endl;
	prvNh.param<int>("y1", var, 0);
	std::cout << " read position y1: " << var << std::endl;
	prvNh.param<int>("yaw1", var, 0);
	std::cout << " read param yaw1: " << var << std::endl;

	// parameters position 2

	prvNh.param<int>("x2", var, 0);
	std::cout << " read position x2: " << var << std::endl;
	prvNh.param<int>("y2", var, 0);
	std::cout << " read position y2: " << var << std::endl;
	prvNh.param<int>("yaw2", var, 0);
	std::cout << " read param yaw2: " << var << std::endl;

	// parameters position 3

	prvNh.param<int>("x3", var, 0);
	std::cout << " read position x3: " << var << std::endl;
	prvNh.param<int>("y3", var, 0);
	std::cout << " read position y3: " << var << std::endl;
	prvNh.param<int>("yaw3", var, 0);
	std::cout << " read param yaw3: " << var << std::endl;



	ros::Subscriber sub = prvNh.subscribe("Android", 1, androidIDCallback);
	//targetPositions = prvNh.advertise<std_msgs::Int8>("hier noch Zielpfad", 1);


	//ros::spin(); 

		
}
