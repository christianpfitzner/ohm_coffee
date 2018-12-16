#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/String.h"
#include <vector>
#include <iostream>
#include <algorithm>




void androidIDCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_DEBUG("Android ID: [%s]", msg->data.c_str());

/*
	std::string angelika = "angelika";
	std::string data = msg->data;
	if (data.compare(angelika) == 0)
	{
	std::cout << "perfekt" << std::endl; 
	}
	else
	{
	std::cout << "other name" << std::endl;
	}
*/
/*

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
	//targetPositions.publish();
}






int main(int argc, char** argv)
{

	ros::init(argc, argv, "TargetPositionsNode");

	//private nodehandle for getting parameters out of .yaml-file
	ros::NodeHandle prvNh("~");
	
	//regular nodehandle
	ros::NodeHandle nhServer;

	//defining message for publishing
	geometry_msgs::PoseStamped Target;

	int ID = 0;
	int target_x = 1;
	int target_y = 0;
	int target_z = 0;
		





	//'{ header: { frame_id: map }, pose: { position: { x: 1, y: 1 , z: 0}, orientation: { x: 0, y: 0, z: 0, w: 1 }}}'

	std::string angelika = "angelika";
	std::string data = msg->data;


	XmlRpc::XmlRpcValue ID_list;
	if( !prvNh.getParam("id", ID_list) )
	    ROS_INFO("Still failed...");
	else{
	    ROS_INFO("succes");
	    std::cout << ID_list[0] << std::endl; 
	    std::cout << ID_list[1] << std::endl;
	}

    	std::vector<std::string> persons;

	for(int i=0; i < ID_list.size(); i++)
	{
		persons.push_back(ID_list[i]);
	}	

		//"angelika" noch variabel gestalten!
    	int pos = std::find(persons.begin(), persons.end(), data "angelika") - persons.begin();
    
    	if(pos < persons.size())
        	std::cout << "Position :" << pos << std::endl;
    	else
        	std::cout << "ID not found... please check" << std::endl;


		//getting parameters

	Target.header.frame_id = "map";	
	Target.pose.position.x	= ID_list[1];
/*	Target.pose.position.y = ID_list[2];
	Target.pose.position.z = 0;
	Target.pose.orientation.x = 0;
	Target.pose.orientation.y = 0;
	Target.pose.orientation.z = 0;
	Target.pose.orientation.w = ID_list[3];*/

	std::cout << "testParam2 :" << Target.pose.position.x << std::endl;
	




	//übergabe idee.. 
	//param.pose.x = Position_list[pos]

	//subscribing to input from app-server

	ros::Subscriber sub = nhServer.subscribe("Android", 1, androidIDCallback);

	//publisher for navigation goals

	ros::Publisher targetPos = nhServer.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1);
	
	//targetPos = prvNh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal/geometry_msgs/PoseStamped", 1);

	//publishing targets
	targetPos.publish(Target);

	ros::spin();

	while(ros::ok())
	{
		ros::spinOnce();
	}


	ros::Rate rate(10); 
	while(ros::ok())
	{
		targetPos.publish(Target);
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		ros::spinOnce(); 
		//rate.sleep(); 	
	}
		
}
