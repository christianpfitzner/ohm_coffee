#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include "std_msgs/String.h"





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

	geometry_msgs::PoseStamped Target;

	ros::init(argc, argv, "TargetPositionsNode");
	
	int ID = 0;

	int target_x = 0;
	int target_y = 0;
	int target_z = 0;
	
	
	ros::NodeHandle prvNh("~");
	ros::NodeHandle nhServer;


	// parameters position 1

	prvNh.param<int>("x1", target_x, 0);
	std::cout << "testParam1 :" << target_x << std::endl;

	Target.header.frame_id = "map";	
	Target.pose.position.x	= target_x;
	Target.pose.position.y = 2;
	Target.pose.position.z = 0;
	Target.pose.orientation.x = 0;
	Target.pose.orientation.y = 0;
	Target.pose.orientation.z = 0;
	Target.pose.orientation.w = 1;
	std::cout << "testParam2 :" << Target.pose.orientation.w << std::endl;
	


	//'{ header: { frame_id: map }, pose: { position: { x: 1, y: 1 , z: 0}, orientation: { x: 0, y: 0, z: 0, w: 1 }}}'



	ros::Subscriber sub = nhServer.subscribe("Android", 1, androidIDCallback);


	XmlRpc::XmlRpcValue param_list;
	if( !prvNh.getParam("x", param_list) )
	    ROS_INFO("Still failed...");
	else{
	    ROS_INFO("succes");
	    std::cout << param_list[0] << std::endl; 
	}

	ros::Publisher targetPos = nhServer.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1);
	//targetPos = prvNh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal/geometry_msgs/PoseStamped", 1);


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
