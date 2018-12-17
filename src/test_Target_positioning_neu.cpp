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





	//targetPos.publish(Target);
}






int main(int argc, char** argv)
{

	ros::init(argc, argv, "TargetPositionsNode");

	ros::NodeHandle prvNh("~");
	ros::NodeHandle nhServer;

	geometry_msgs::PoseStamped Target;




	ros::Subscriber sub = nhServer.subscribe("Android", 1, androidIDCallback);

		//vektor-name hier variabel?! 
	XmlRpc::XmlRpcValue ID_list;
	XmlRpc::XmlRpcValue x_list;
	XmlRpc::XmlRpcValue y_list;

	if (!prvNh.getParam("id", ID_list)) 
	{
	ROS_ERROR("failed to get data - check ID!");
	return(0);
	}
	else{
	    ROS_INFO("ID-param ok");
	    std::cout << "ID : " << ID_list[1] << std::endl;
	    }

	if(!prvNh.getParam("x", x_list)) 
	{
	ROS_ERROR("failed to get data - check x-positions!");
	return(0);
	}
	else{
	    ROS_INFO("x-param ok");
	    std::cout << "x : " << x_list[0] << std::endl;
	    }

	if (!prvNh.getParam("y", y_list)) 
	{
   	ROS_ERROR("failed to get data - check y-positions!");
	return(0);
	}
	else{
	    ROS_INFO("y-param ok");
	    std::cout << "y : " << x_list[0] << std::endl;
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
	Target.pose.position.x = x_list[0];
/*	Target.pose.position.y = y_list[pos];
	Target.pose.orientation.w = 1;*/

	//std::cout << "testParam2 :" << Target.pose.position.x << std::endl;
	

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
