#include "../include/ros_connect.h"
#include "../include/motor_drive.h"

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>

NodeHandle nh;

std_msgs::Float64 thumb_flex_msg;
std_msgs::Float64 thumb_abd_msg;

std_msgs::Float64 index_flex_msg;
std_msgs::Float64 index_abd_msg;

std_msgs::Float64 middle_flex_msg;
std_msgs::Float64 middle_abd_msg;

std_msgs::Float64 ring_flex_msg;
std_msgs::Float64 ring_abd_msg;

std_msgs::Float64 pinky_flex_msg;
std_msgs::Float64 pinky_abd_msg;

std_msgs::Float64 wrist_flex_msg;

std_msgs::String debug_msg;


ros::Publisher debug_pub("/debug", &debug_msg);

ros::Subscriber<std_msgs::Float64> thumb_flex_sub ("/actuation/thumb/flex", &thumb_flex_cb);
ros::Subscriber<std_msgs::Float64> thumb_abd_sub  ("/actuation/thumb/abd",  &thumb_abd_cb);
ros::Subscriber<std_msgs::Float64> index_flex_sub ("/actuation/index/flex", &index_flex_cb);
ros::Subscriber<std_msgs::Float64> index_abd_sub  ("/actuation/index/abd",  &index_abd_cb);
ros::Subscriber<std_msgs::Float64> middle_flex_sub("/actuation/middle/flex",&middle_flex_cb);
ros::Subscriber<std_msgs::Float64> middle_abd_sub ("/actuation/middle/abd", &middle_abd_cb);
ros::Subscriber<std_msgs::Float64> ring_flex_sub  ("/actuation/ring/flex",  &ring_flex_cb);
ros::Subscriber<std_msgs::Float64> ring_abd_sub   ("/actuation/ring/abd",   &ring_abd_cb);
ros::Subscriber<std_msgs::Float64> pinky_flex_sub ("/actuation/pinky/flex", &pinky_flex_cb);
ros::Subscriber<std_msgs::Float64> pinky_abd_sub  ("/actuation/pinky/abd",  &pinky_abd_cb);
ros::Subscriber<std_msgs::Float64> wrist_flex_sub ("/actuation/wrist/flex", &wrist_flex_cb);
    

void thumb_flex_cb (const std_msgs::Float64 &thumb_flex_msg);
void thumb_abd_cb  (const std_msgs::Float64 &thumb_abd_msg);
void index_flex_cb (const std_msgs::Float64 &index_flex_msg);
void index_abd_cb  (const std_msgs::Float64 &index_abd_msg);
void middle_flex_cb(const std_msgs::Float64 &middle_flex_msg);
void middle_abd_cb (const std_msgs::Float64 &middle_abd_msg);
void ring_flex_cb  (const std_msgs::Float64 &ring_flex_msg);
void ring_abd_cb   (const std_msgs::Float64 &ring_abd_msg);
void pinky_flex_cb (const std_msgs::Float64 &pinky_flex_msg);
void pinky_abd_cb  (const std_msgs::Float64 &pinky_abd_msg);
void wrist_flex_cb (const std_msgs::Float64 &wrist_flex_msg);


void initROS() {
  nh.initNode();
  
  // #### Subscribers
  nh.subscribe(thumb_flex_sub);
  nh.subscribe(thumb_abd_sub);
  nh.subscribe(index_flex_sub);
  nh.subscribe(index_abd_sub);
  nh.subscribe(middle_flex_sub);
  nh.subscribe(middle_abd_sub);
  nh.subscribe(ring_flex_sub);
  nh.subscribe(ring_abd_sub);
  nh.subscribe(pinky_flex_sub);
  nh.subscribe(pinky_abd_sub);
  nh.subscribe(wrist_flex_sub);

  // #### Publishers
  nh.advertise(debug_pub);
  
  // give serial_node.py a chance to get to know the topics
  nh.negotiateTopics();

}