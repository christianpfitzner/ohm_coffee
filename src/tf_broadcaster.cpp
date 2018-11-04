#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
	//publisher for tf data
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(n.ok())
  {
    broadcaster.sendTransform(
      tf::StampedTransform(
		//assuming the sensors offset from baselink is 10cm on x-achsis, no rotation yet
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.0)),
        ros::Time::now(),"base_link", "base_ir_sensor_center"));
    broadcaster.sendTransform(
      tf::StampedTransform(
		//assuming the sensors offset from baselink is 10cm on x-achsis, no rotation yet
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.0)),
        ros::Time::now(),"base_link", "base_ir_sensor_left"));
    broadcaster.sendTransform(
      tf::StampedTransform(
		//assuming the sensors offset from baselink is 10cm on x-achsis, no rotation yet
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.0)),
        ros::Time::now(),"base_link", "base_ir_sensor_right"));
    r.sleep();
  }
}

