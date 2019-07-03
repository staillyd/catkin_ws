#!/usr/bin/env python  
#coding:utf-8

#tf.TransformBroadcaster类的第二种发布形式
from __future__ import print_function
import rospy
import tf
import geometry_msgs.msg
if __name__ == "__main__":
    rospy.init_node('py_tf_broadcaster2')
    br=tf.TransformBroadcaster()
    t=geometry_msgs.msg.TransformStamped()
    t.header.frame_id='base_link'
    t.header.stamp=rospy.Time(0)
    t.child_frame_id='link1'
    t.transform.translation.x=1
    t.transform.translation.y=2
    t.transform.translation.z=3
    t.transform.rotation.w=1
    t.transform.rotation.x=0
    t.transform.rotation.y=0
    t.transform.rotation.z=0
    rate=rospy.Rate(1)
    while not rospy.is_shutdown():
        br.sendTransformMessage(t)
        rate.sleep()