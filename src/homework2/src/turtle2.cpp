#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <turtlesim/Spawn.h>

// 接收到订阅的消息后，会进入消息回调函数
void chatterCallback(const turtlesim::Pose::ConstPtr& msg)
{
  // 将接收到的消息打印出来
//   std::cout<<msg->x<<" "<<std::endl;
  ROS_INFO("turtle2 x:%f,y:%f", msg->x,msg->y);
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"turtle2");
    ros::NodeHandle node;

    // 通过服务调用，产生第二只乌龟turtle2
    ros::service::waitForService("spawn");
    ros::ServiceClient add_turtle =node.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn srv;
    srv.request.x=5;srv.request.y=5;
    add_turtle.call(srv);

    // 创建一个Subscriber，订阅名为chatter的topic，注册回调函数chatterCallback
    ros::Subscriber sub = node.subscribe("turtle2/pose", 10, chatterCallback);

    // 定义turtle2的速度控制发布器
    ros::Publisher turtle_vel =node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);

    ros::Rate rate(10.0);
    while (node.ok()){
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 1;
        vel_msg.linear.x = 1;
        //向前和旋转两种移动方式
        turtle_vel.publish(vel_msg);
        
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
