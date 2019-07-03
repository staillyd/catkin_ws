#include <ros/ros.h>
#include <my_service_demo/my_greeting.h>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"my_greetings_client");//初始化,节点命名为"my_greetings_client"
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<my_service_demo::my_greeting>("my_greetings");

    //实例化srv,设置其request消息的内容,这里request包含两个变量,name和age,见Greeting.srv
    my_service_demo::my_greeting srv;
    srv.request.name="Lan";
    srv.request.age=23;

    if(client.call(srv)){//发送请求,如果服务器应答
        ROS_INFO("response from server:%s",srv.response.feedback.c_str());
    }else{
        ROS_ERROR("failed to call service my_service_demo");
        return 1;
    }

    return 0;
}
