#include <ros/rate.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_listener.h>


void transformPoint(const tf::TransformListener& listener){
    geometry_msgs::PointStamped laser_point;//定义在base_laser坐标系下的一个坐标
    laser_point.header.frame_id="base_laser";
    laser_point.header.stamp=ros::Time();//用最新的tf变换
    laser_point.point.x=0.3;
    laser_point.point.y=0.0;
    laser_point.point.z=0.0;

    try
    {
        geometry_msgs::PointStamped base_point;//变换到base坐标系下的坐标
        listener.transformPoint("base_link",laser_point,base_point);
        ROS_INFO("base_laser: (%.2f, %.2f. %.2f) -----> base_link: (%.2f, %.2f, %.2f) at time %.2f",
            laser_point.point.x, laser_point.point.y, laser_point.point.z,
            base_point.point.x, base_point.point.y, base_point.point.z, base_point.header.stamp.toSec());
    }
    catch(tf::TransformException& e)
    {
        ROS_ERROR("Received an exception trying to transform a point from \"base_laser\" to \"base_link\": %s", e.what());
    }
    
}


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"robot_tf_sub");
    ros::NodeHandle node;

    tf::TransformListener listener(ros::Duration(10));

    ros::Timer timer = node.createTimer(ros::Duration(1.0),
                        boost::bind(&transformPoint,boost::ref(listener)));
    ros::spin();
    return 0;
}
