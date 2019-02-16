#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

#include <ros/ros.h>
#include <std_msgs/String.h>

/* 
*	Implementation of the Simple_server_main class
*	The simple_server_main.cpp file contains a ROS node. 
*	All the names markes ros:: are ROS specific.
*	@param: ros::init initializes a node with specific name
*	@parma: ros:: NodeHandle creat a Ros node
*	@parma: ros:: Publisher creat a publisher node which broadcast information
*	@paramfunction: ServerSocket creat which listen to a specific port
* 	@param: ServerSocket creat a new socket
*	
*	The message sent via the server client connetion is forwarded to the Ros accounts. 
*	If the message does not contain an error, it will be interrupted.
*/

int main(int argc, char** argv)
{
	
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
