#!/usr/bin/env python  
#coding:utf-8

#tf.TransformBroadcaster类的第一种发布形式
from __future__ import print_function
import rospy
import tf
if __name__ == "__main__":
    rospy.init_node("py_tf_broadcaster")
    br=tf.TransformBroadcaster()
    x,y,z=1,2,3
    roll,pitch,yaw=0,0,1.57
    rate=rospy.Rate(1)
    while not rospy.is_shutdown():
        yaw+=0.1
        br.sendTransform((x,y,z),
                        tf.transformations.quaternion_from_euler(roll,pitch,yaw),
                        rospy.Time.now(),
                        "link1",
                        "base_link")#发布base_link到link1的平移和翻转
        rate.sleep()