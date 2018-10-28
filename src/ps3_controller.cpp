#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include "ohm_coffee/ps3_controller.h"

ros::Publisher pubTwist;

void ps3ControllerCallback(const sensor_msgs::Joy& msg)
{
    
    //Check ob Controller in der Hand über Bewegungssensoren
    
/*
	bool enabled;

        if(msg.axes.AXIS_ACCELEROMETER_LEFT < 0.2 && msg.axes.AXIS_ACCELEROMETER_LEFT > -0.2
	|| msg.axes.AXIS_ACCELEROMETER_FORWARD < 0.2 && msg.axes.AXIS_ACCELEROMETER_FORWARD > -0.2 )
		enabled = false;
	else
		enabled = true;
*/

	geometry_msgs::Twist velocity;

        //Einlesen der Achsen
        velocity.angular.z = msg.axes[AXIS_STICK_RIGHT_HORIZONTAL];
        velocity.linear.x  = msg.axes[AXIS_STICK_LEFT_VERTICAL];

         //Sinn und Zweck dieser beiden Zeilen?!
        std::cout << "angular: " << velocity.angular.z << std::endl;
        std::cout << "linear:  " << velocity.linear.x  << std::endl;

         //publishing data
	pubTwist.publish(velocity);
	


	// Umrechnung von Controller Input auf Roboter Output und abspeichern
	// Voller Stickausschlag bedeutet 1 m/s, Verlauf lin/exp?
	//ps3Val.angular = 1 * msg.axes.0 * int(enabled);
	//ps3Val.linear = 1 * msg.axes.3 * int(enabled);


	std::cout << __PRETTY_FUNCTION__ << std::endl; 
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "ps3_controller");

	ros::NodeHandle nh;
	


	ros::Subscriber subJoy  = nh.subscribe("joy", 1, ps3ControllerCallback);
	pubTwist = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

	

	ros::spin(); 

}
