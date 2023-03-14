#ifndef INCLUDE_ROS_CONNECT_H
#define INCLUDE_ROS_CONNECT_H

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <tf/tf.h>

typedef ros::NodeHandle_<ArduinoHardware, 25, 25, 2048, 2048>
    NodeHandle; // default 25, 25, 512, 512

// ====================ROS shit=========================================
extern NodeHandle nh;

// msgs
extern std_msgs::Float64 thumb_flex_msg;
extern std_msgs::Float64 thumb_right_msg;
extern std_msgs::Float64 index_flex_msg;
extern std_msgs::Float64 index_right_msg;
extern std_msgs::Float64 middle_flex_msg;
extern std_msgs::Float64 middle_right_msg;
extern std_msgs::Float64 ring_flex_msg;
extern std_msgs::Float64 ring_right_msg;
extern std_msgs::Float64 pinky_flex_msg;
extern std_msgs::Float64 pinky_right_msg;
extern std_msgs::Float64 wrist_flex_msg;

extern std_msgs::String debug_msg;

extern ros::Publisher debug_pub;

// init
void initROS();

// callbacks
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

void debug_cb(const std_msgs::String debug_msg);

#endif // INCLUDE_ROS_CONNECT_H