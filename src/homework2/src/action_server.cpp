//相当于机器人
#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <homework2/tmpAction.h>//自定义的消息

typedef actionlib::SimpleActionServer<homework2::tmpAction> Server;//tmpAction

// 收到action的goal后调用该回调函数
void execute(const homework2::tmpGoalConstPtr& goal, Server* as){//tmpGoal 没有action
    ros::Rate r(1);
    homework2::tmpFeedback feedback;

    ROS_INFO("set goal:x:%d,y:%d", goal->x,goal->y);

    // 假设洗盘子的进度，并且按照1hz的频率发布进度feedback
    for(int i=1; i<=10; i++)
    {
        feedback.percent_complete = i * 10;
        as->publishFeedback(feedback);
        r.sleep();
    } 

    // 当action完成后，向客户端返回结果
    homework2::tmpResult result;
    result.isDone=true;
    ROS_INFO("achive the goal:x:%d,y:%d.",goal->x,goal->y);
    as->setSucceeded(result);
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"robot");
    ros::NodeHandle node;

    Server server(node, "action_name", boost::bind(&execute, _1, &server), false);

    // 服务器开始运行
    server.start();

    ros::spin();

    return 0;
}
