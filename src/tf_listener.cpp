#include <ros/ros.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_listener.h>

void transformPoint(const tf::TransformListener& listener){
  	//creation of a point in the base_ir_sensor_center frame that's going to be transformed to the base_link frame
  geometry_msgs::PointStamped sensor_point;
  sensor_point.header.frame_id = "base_ir_sensor_center";

  	//most recent transform available, timestamp from broadcaster
  sensor_point.header.stamp = ros::Time();

  	//just an arbitrary point
  sensor_point.point.x = 1.0;
  sensor_point.point.y = 0.2;
  sensor_point.point.z = 0.0;

  try{
    geometry_msgs::PointStamped base_point;

	//name of transformed frame, transformed point, storage for transformed point    
    listener.transformPoint("base_link", sensor_point, base_point);

	//output info for points, not necessary for function
    ROS_INFO("base_ir_sensor_center: (%.2f, %.2f. %.2f) -----> base_link: (%.2f, %.2f, %.2f) at time %.2f",
        sensor_point.point.x, sensor_point.point.y, sensor_point.point.z,
        base_point.point.x, base_point.point.y, base_point.point.z, base_point.header.stamp.toSec());
  }

	//print out an error if transform unavailable
  catch(tf::TransformException& ex){
    ROS_ERROR("Received an exception trying to transform a point from \"base_ir_sensor_center\" to \"base_link\": %s", ex.what());
  }
}

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_listener");
  ros::NodeHandle n;

  tf::TransformListener listener(ros::Duration(10));

  //transform a point once per second
  ros::Timer timer = n.createTimer(ros::Duration(1.0), boost::bind(&transformPoint, boost::ref(listener)));

  ros::spin();

}
