#!/usr/bin/env python
#coding=utf-8
import rospy
from my_service_demo.srv import *

def client_srv():
    rospy.init_node("pyGreeting_client")
    #等待有可用的服务"my_greetings"
    rospy.wait_for_service("my_greetings")
    try:
        #定义service客户端,service名称为“greetings”,service类型为Greeting
        greeting_client=rospy.ServiceProxy("my_greetings",my_greeting)
        resp=greeting_client.call("Lan",23)
        rospy.loginfo("message from server:%s"%resp.feedback)
    except rospy.ServiceException as e:
        rospy.logwarn("Service call failed:%s"%e)

if __name__ == "__main__":
    client_srv()