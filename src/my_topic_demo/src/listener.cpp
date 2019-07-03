#include <ros/ros.h>

#include <my_topic_demo/gps.h>
#include <std_msgs/Float32.h>
void gpsCallback(const my_topic_demo::gps::ConstPtr &msg){
    std_msgs::Float32 distance;
    distance.data=sqrt(pow(msg->x,2)+pow(msg->y,2));
    ROS_INFO("subscribe:distance:%f,state:%s",distance.data,msg->state.c_str());
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"my_listener");
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("my_gps_info",1,gpsCallback);//设置回调函数
    ros::spin();
    //ros::spin()用于调用所有可触发的回调函数,将进入循环,不会返回,类似于在循环里反复调用spinOnce()	
	//而ros::spinOnce()只会去触发一次
    return 0;
}
