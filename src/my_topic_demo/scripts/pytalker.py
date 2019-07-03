#!/usr/bin/env python
#coding=utf-8
import rospy
from my_topic_demo.msg import gps

def talker():
    rospy.init_node("my_pytalker",anonymous=True)
    #1.话题名称   2.msg类型   3.队列长度
    pub=rospy.Publisher("my_gps_info",gps,queue_size=10)
    rate=rospy.Rate(1)#1Hz
    x,y,state=1.0,1.0,"working"
    while not rospy.is_shutdown():
        rospy.loginfo('pytalker: gps:x=%f,y=%f',x,y)
        pub.publish(gps(state,x,y))
        x,y=1.03*x,1.03*y
        rate.sleep()

if __name__ == "__main__":
    talker()