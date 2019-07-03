#include <ros/ros.h>
#include <my_topic_demo/gps.h>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"my_talker");//用于解析ROS参数,第三个参数为本节点的名称
    ros::NodeHandle nh;//实例化句柄,初始化node

    my_topic_demo::gps msg;//自定义gps消息并初始化
    msg.state="working";
    msg.x=1.0;
    msg.y=1.0;

    //创建publisher,往"gps_info"话题上发布消息
    ros::Publisher pub=nh.advertise<my_topic_demo::gps>("my_gps_info",1);

    ros::Rate loop_rate(1.0);//定义发布频率 1Hz
    while(ros::ok()){
        msg.x*=1.03;//让msg信息随指数增长
        msg.y*=1.03;
        ROS_INFO("publisher:x:%f,y:%f",msg.x,msg.y);

        pub.publish(msg);//发布消息
        loop_rate.sleep();//根据前面定义的loop_rate设置1s的暂停
    }
    return 0;
}


