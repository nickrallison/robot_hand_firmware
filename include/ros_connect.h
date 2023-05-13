#ifndef INCLUDE_ROS_CONNECT_H
#define INCLUDE_ROS_CONNECT_H

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64MultiArray.h>
#include <tf/tf.h>

typedef ros::NodeHandle_<ArduinoHardware, 25, 25, 2048, 2048>
    NodeHandle; // default 25, 25, 512, 512

// ====================ROS shit=========================================
extern NodeHandle nh;

// msgs
extern std_msgs::Float64 thumb_flex_msg;
extern std_msgs::Float64 thumb_abd_msg;
extern std_msgs::Float64 index_flex_msg;
extern std_msgs::Float64 index_abd_msg;
extern std_msgs::Float64 middle_flex_msg;
extern std_msgs::Float64 middle_abd_msg;
extern std_msgs::Float64 ring_flex_msg;
extern std_msgs::Float64 ring_abd_msg;
extern std_msgs::Float64 pinky_flex_msg;
extern std_msgs::Float64 pinky_abd_msg;
extern std_msgs::Float64 wrist_flex_msg;
extern std_msgs::Float64 percent_msg;

extern std_msgs::String debug_msg;

extern std_msgs::Float64MultiArray audio_msg;

extern ros::Publisher debug_pub;
extern ros::Publisher percent_pub;
extern ros::Publisher audio_pub;


// init
void initROS();

// callbacks
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

void debug_cb(const std_msgs::String debug_msg);

#endif // INCLUDE_ROS_CONNECT_H