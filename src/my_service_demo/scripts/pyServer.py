#!/usr/bin/env python
#coding=utf-8
import rospy
from my_service_demo.srv import *

def server_srv():
    rospy.init_node("pyGreeting_server")
    #定义服务端
    s=rospy.Service("my_greetings",my_greeting,handler)
    rospy.loginfo("Ready to handle the Request:")
    rospy.spin()

def handler(req):
    rospy.loginfo("Request from %s with age %d",req.name,req.age)
    return my_greetingResponse("Hi %s. I'm Server!"%req.name)

if __name__ == "__main__":
    server_srv()

