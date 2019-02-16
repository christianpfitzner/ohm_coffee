//unnecessary test file

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include "ohm_coffee/ps3_controller.h"

ros::Publisher pubVel;

void TB_control_Callback(const sensor_msgs::Joy& msg)
{

	geometry_msgs::Twist velocity;

        //read data from joystick
        //velocity.angular.z = msg.axes[AXIS_STICK_RIGHT_HORIZONTAL];
	velocity.angular.z = msg.axes[AXIS_STICK_RIGHT_VERTICAL];
        velocity.linear.x  = msg.axes[AXIS_STICK_LEFT_VERTICAL];

        std::cout << "angular: " << velocity.angular.z << std::endl;
        std::cout << "linear:  " << velocity.linear.x  << std::endl;

	pubVel.publish(velocity);
	

	std::cout << __PRETTY_FUNCTION__ << std::endl; 
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "turtlebot_controller");

	ros::NodeHandle nh;
	
	ros::Subscriber subJoy  = nh.subscribe("joy", 1, TB_control_Callback);
	pubVel = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);
	//pubVel = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
	//pubVel = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/motor_power", 1);

	

	ros::spin(); 

}
