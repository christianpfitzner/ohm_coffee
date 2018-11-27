#include <ros/ros.h>


//ros::Publisher pubParam;

int main(int argc, char** argv)
{

	ros::init(argc, argv, "positioning_node");
	int var = 0;
	std::string s;
	

	ros::NodeHandle prvNh("~");

	prvNh.param<int>("x1", var, 4711);
	std::cout << " read param x: " << var << std::endl;

        prvNh.param<int>("y2", var, 4711);
	std::cout << " read param y: " << var << std::endl;

	prvNh.param<std::string>("testString", s, "nix");
	std::cout << " read string :" << s << std::endl;



		

	//pubParam = nh.advertise<std_msgs::Int8>("yaml_Parameter", 1);	

	//pubParam.publish(msg);
}
