#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"robot_tf_pub");
    ros::NodeHandle node;

    ros::Rate r(100);
    tf::TransformBroadcaster br;

    while(ros::ok()){
        br.sendTransform(tf::StampedTransform(
                tf::Transform(tf::Quaternion(0,0,0,1),tf::Vector3(0.1,0.0,0.2)),
                ros::Time::now(),"base_link","base_laser"));//发送base_link-->bae_laser的tf变换
        r.sleep();
    }
    
    return 0;
}
