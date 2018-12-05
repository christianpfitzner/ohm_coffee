#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv)
{
	std::cout << "Hallo Wo" << std::endl;
	ros::init (argc, argv,  "androidID");
	ros::NodeHandle nhServer;
	ros::Publisher android_pub = nhServer.advertise<std_msgs::String>("Android" , 1000);
	try
	{
		ServerSocket server(7850);
	while(true)
	{		
	ServerSocket new_sock;
	server.accept(new_sock);
		try
		{ while(true)
		{
		std_msgs::String msg;
		std::string data;
		new_sock >> data;
std::cout << data << std::endl;
		msg.data = data;
		android_pub.publish(msg);
		}
		}
		catch (SocketException&) {}

		}
		}
catch (SocketException & e)
{
std::cout << "Error" << e.description () << "\nExiting. \n";
}
return 0;
}
