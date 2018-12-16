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
	ROS_DEBUG("Android ID: [%s]", msg->data.c_str());


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





	//targetPos.publish();
}






int main(int argc, char** argv)
{

	ros::init(argc, argv, "TargetPositionsNode");

	ros::NodeHandle prvNh("~");
	ros::NodeHandle nhServer;

	geometry_msgs::PoseStamped Target;




	ros::Subscriber sub = nhServer.subscribe("Android", 1, androidIDCallback);

		//vektor-name hier variabel.. 
	XmlRpc::XmlRpcValue ID_list;

	if (!prvNh.getParam("id", ID_list) )
	    ROS_INFO("failed to get data...");
	else{
	    ROS_INFO("succes");
	    std::cout << "ID : " << ID_list[1] << std::endl; 
	    std::cout << ID_list[1] << std::endl;
	}


    	std::vector<std::string> persons;

	for(int i=0; i < ID_list.size(); i++)
	{
		persons.push_back(ID_list[i]);
	}	

	
/*
		//"angelika" noch variabel gestalten!
    	//int pos = std::find(ID_list.begin(), ID_list.end(), data "angelika") - ID_list.begin();
    
	int pos = std::find(ID_list.begin(), ID_list.end(), data "angelika") - ID_list.begin();
    
    	if(pos < ID_list.size())
        	std::cout << "Position :" << pos << std::endl;
    	else
        	std::cout << "ID not found... please check" << std::endl;

*/


	Target.header.frame_id = "map";	
	Target.pose.position.x	= 2;
/*	Target.pose.position.y = ID_list[2];
	Target.pose.orientation.w = ID_list[3];*/

	std::cout << "testParam2 :" << Target.pose.position.x << std::endl;
	

	ros::Publisher targetPos = nhServer.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1);


	//publish
	targetPos.publish(Target);

	//ros::spin();

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
