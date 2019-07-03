//相当于操作界面
#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <homework2/tmpAction.h>

typedef actionlib::SimpleActionClient<homework2::tmpAction> Client;

// 当action完成后会调用该回调函数一次
void doneCb(const actionlib::SimpleClientGoalState& state,
        const homework2::tmpResultConstPtr& result)
{
    ROS_INFO("Yay! get the goal: %d",result->isDone);
    ros::shutdown();
}

// 当action激活后会调用该回调函数一次
void activeCb()
{
    ROS_INFO("Goal just went active");
}

// 收到feedback后调用该回调函数
void feedbackCb(const homework2::tmpFeedbackConstPtr& feedback)
{
    ROS_INFO(" percent_complete : %f ", feedback->percent_complete);
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"control");
    
    // 定义一个客户端
    Client client("action_name", true);

    // 等待服务器端
    ROS_INFO("Waiting for action server to start.");
    client.waitForServer();
    ROS_INFO("Action server started, sending goal.");

    // 创建一个action的goal
    homework2::tmpGoal goal;
    goal.x = 1;
    goal.y = 1;

    // 发送action的goal给服务器端，并且设置回调函数
    client.sendGoal(goal,&doneCb, &activeCb, &feedbackCb);
    ros::spin();

    return 0;
}

