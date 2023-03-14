#include "../include/ros_connect.h"
#include "../include/motor_drive.h"

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>

NodeHandle nh;

std_msgs::Float64 thumb_flex_msg;
std_msgs::Float64 thumb_right_msg;

std_msgs::Float64 index_flex_msg;
std_msgs::Float64 index_right_msg;

std_msgs::Float64 middle_flex_msg;
std_msgs::Float64 middle_right_msg;

std_msgs::Float64 ring_flex_msg;
std_msgs::Float64 ring_right_msg;

std_msgs::Float64 pinky_flex_msg;
std_msgs::Float64 pinky_right_msg;

std_msgs::Float64 wrist_flex_msg;

std_msgs::String debug_msg;


ros::Publisher debug_pub("/debug", &debug_msg);

ros::Subscriber<std_msgs::Float64> thumb_flex_sub ("/actuation/thumb/flex", &thumb_flex_cb);
ros::Subscriber<std_msgs::Float64> thumb_right_sub  ("/actuation/thumb/right",  &thumb_right_cb);
ros::Subscriber<std_msgs::Float64> index_flex_sub ("/actuation/index/flex", &index_flex_cb);
ros::Subscriber<std_msgs::Float64> index_right_sub  ("/actuation/index/right",  &index_right_cb);
ros::Subscriber<std_msgs::Float64> middle_flex_sub("/actuation/middle/flex",&middle_flex_cb);
ros::Subscriber<std_msgs::Float64> middle_right_sub ("/actuation/middle/right", &middle_right_cb);
ros::Subscriber<std_msgs::Float64> ring_flex_sub  ("/actuation/ring/flex",  &ring_flex_cb);
ros::Subscriber<std_msgs::Float64> ring_right_sub   ("/actuation/ring/right",   &ring_right_cb);
ros::Subscriber<std_msgs::Float64> pinky_flex_sub ("/actuation/pinky/flex", &pinky_flex_cb);
ros::Subscriber<std_msgs::Float64> pinky_right_sub  ("/actuation/pinky/right",  &pinky_right_cb);
ros::Subscriber<std_msgs::Float64> wrist_flex_sub ("/actuation/wrist/flex", &wrist_flex_cb);
    

void thumb_flex_cb (const std_msgs::Float64 &thumb_flex_msg);
void thumb_right_cb  (const std_msgs::Float64 &thumb_right_msg);
void index_flex_cb (const std_msgs::Float64 &index_flex_msg);
void index_right_cb  (const std_msgs::Float64 &index_right_msg);
void middle_flex_cb(const std_msgs::Float64 &middle_flex_msg);
void middle_right_cb (const std_msgs::Float64 &middle_right_msg);
void ring_flex_cb  (const std_msgs::Float64 &ring_flex_msg);
void ring_right_cb   (const std_msgs::Float64 &ring_right_msg);
void pinky_flex_cb (const std_msgs::Float64 &pinky_flex_msg);
void pinky_right_cb  (const std_msgs::Float64 &pinky_right_msg);
void wrist_flex_cb (const std_msgs::Float64 &wrist_flex_msg);


void initROS() {
  nh.initNode();
  
  // #### Subscribers
  nh.subscribe(thumb_flex_sub);
  nh.subscribe(thumb_right_sub);
  nh.subscribe(index_flex_sub);
  nh.subscribe(index_right_sub);
  nh.subscribe(middle_flex_sub);
  nh.subscribe(middle_right_sub);
  nh.subscribe(ring_flex_sub);
  nh.subscribe(ring_right_sub);
  nh.subscribe(pinky_flex_sub);
  nh.subscribe(pinky_right_sub);
  nh.subscribe(wrist_flex_sub);

  // #### Publishers
  nh.advertise(debug_pub);
  
  // give serial_node.py a chance to get to know the topics
  nh.negotiateTopics();

}