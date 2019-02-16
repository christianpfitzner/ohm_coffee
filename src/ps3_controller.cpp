//this node is used for reading input data from a PS3-controller and publish them for controlling the turtlesim-simulation.

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include "ohm_coffee/ps3_controller.h"

ros::Publisher pubTwist;

void ps3ControllerCallback(const sensor_msgs::Joy& msg)
{
    
	//defining type of published data
	geometry_msgs::Twist velocity;

        //read data from joystick
        velocity.angular.z = msg.axes[AXIS_STICK_RIGHT_HORIZONTAL];
        velocity.linear.x  = msg.axes[AXIS_STICK_LEFT_VERTICAL];

	//terminal output for controlling published data
        std::cout << "angular: " << velocity.angular.z << std::endl;
        std::cout << "linear:  " << velocity.linear.x  << std::endl;

        //publishing data
	pubTwist.publish(velocity);
	

	std::cout << __PRETTY_FUNCTION__ << std::endl; 
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "ps3_controller");

	ros::NodeHandle nh;
	
	//defining publisher and subscriber
	ros::Subscriber subJoy  = nh.subscribe("joy", 1, ps3ControllerCallback);
	pubTwist = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

	

	ros::spin(); 

}
