//this node is used for reading input data from a PS3-controller and publish them for controlling kobuki. Can be used for real kobuki as well as for a simulated one.

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include "ohm_coffee/ps3_controller.h"

//creating a publisher
ros::Publisher pubVel;

//callback funktion for publishing controller-input
void kobukiControllerCallback(const sensor_msgs::Joy& msg)
{
	//defining type of published data
	geometry_msgs::Twist velocity;

        //read data from joystick
	velocity.angular.z = msg.axes[AXIS_STICK_RIGHT_VERTICAL];
        velocity.linear.x  = msg.axes[AXIS_STICK_LEFT_VERTICAL];

	//terminal output for controlling published data
        std::cout << "angular: " << velocity.angular.z << std::endl;
        std::cout << "linear:  " << velocity.linear.x  << std::endl;

	//publish data
	pubVel.publish(velocity);
	

	std::cout << __PRETTY_FUNCTION__ << std::endl; 
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "kobuki_controller");

	ros::NodeHandle nh;
	
	//defining publisher and subscriber
	ros::Subscriber subJoy  = nh.subscribe("joy", 1, kobukiControllerCallback);
	pubVel = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);



	ros::spin(); 

}
