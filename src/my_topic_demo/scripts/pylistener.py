#!/usr/bin/env python
#coding=utf-8
import rospy
import numpy as np
from my_topic_demo.msg import gps

def callBack(gps):
    distance=np.sqrt(pow(gps.x,2)+pow(gps.y,2))
    rospy.loginfo('pylinstener: GPS:distance=%f,state=%s',distance,gps.state)

def listener():
    rospy.init_node('pylistener',anonymous=True)
    #1.topic名称  2.msg类型  3.回调函数
    rospy.Subscriber('my_gps_info',gps,callBack)
    rospy.spin()

if __name__ == "__main__":
    listener()