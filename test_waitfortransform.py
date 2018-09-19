#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
import traceback
import sys
import tf

def waitForTransform():
    rospy.init_node('move_base_bug179_test', anonymous=True)
    listener = tf.TransformListener()

    try:
        now = rospy.Time.now()
        listener.waitForTransform("/map", "/base_link", now, rospy.Duration(0.5))
        (trans,rot) = listener.lookupTransform("/map", "/base_link", now)
    except Exception as e:
        print("Wait for transform failed ----------------------------------")
        print("Error: "+str(e))
        exc_info = sys.exc_info()
        traceback.print_exception(*exc_info)
        del exc_info



if __name__ == '__main__':
    try:
        waitForTransform()
    except rospy.ROSInterruptException:
        pass