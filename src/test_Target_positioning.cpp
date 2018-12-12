#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/String.h"



ros::Publisher targetPos;

void androidIDCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("Android ID: [%s]", msg->data.c_str());


/*	
	if (ID == 123)
	{
	x = 
	y = 
	}

	if (ID == 456)r
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
	//targetPositions.publish();
}






int main(int argc, char** argv)
{

	ros::init(argc, argv, "TargetPositionsNode");
	//int var = 0;
	int ID = 0;

	int target_x = 0;
	int target_y = 0;
	int target_z = 0;

	ros::NodeHandle prvNh("~");


	// parameters position 1

	prvNh.param<int>("x1", target_x, 0);
	std::cout << "testParam1 :" << target_x << std::endl;
	prvNh.param<int>("y1", target_y, 0);
	prvNh.param<int>("yaw1", target_z, 0);


/*
	// parameters position 2

	prvNh.param<int>("x2", target_x, 0);
	prvNh.param<int>("y2", target_y, 0);
	prvNh.param<int>("yaw2", target_z, 0);


	// parameters position 3

	prvNh.param<int>("x3", target_x, 0);
	prvNh.param<int>("y3", target_y, 0);
	prvNh.param<int>("yaw3", target_z, 0);

*/

	ros::Subscriber sub = prvNh.subscribe("Android", 1, androidIDCallback);


/*
	targetPos = prvNh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal geometry_msgs/PoseStamped '{ header: { frame_id: "map" }, pose: { position: { x: 1, y: 1 , z: 0}, orientation: { x: 0, y: 0, z: 0, w: 1 }}}'", 1);
*/
	//targetPositions.publish(PoseStamped);

	ros::spin(); 

		
}
