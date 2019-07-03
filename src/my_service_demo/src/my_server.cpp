#include <ros/ros.h>
#include <my_service_demo/my_greeting.h>

bool handle_function(my_service_demo::my_greeting::Request &req,
                        my_service_demo::my_greeting::Response & res){
    //显示请求信息
    ROS_INFO("Request from %s with age %d",req.name.c_str(),req.age);
    res.feedback="Hi "+req.name+". I'm server";
    return true;
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"my_greetings_server");//解析参数,命名节点
    ros::NodeHandle nh;//创建句柄,实例化node
    ros::ServiceServer service=nh.advertiseService("my_greetings",handle_function);
    ros::spin();
    return 0;
}
