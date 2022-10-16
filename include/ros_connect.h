#ifndef INCLUDE_ROS_CONNECT_H
#define INCLUDE_ROS_CONNECT_H

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float32.h>
#include <tf/tf.h>

typedef ros::NodeHandle_<ArduinoHardware, 25, 25, 2048, 2048>
    NodeHandle;  // default 25, 25, 512, 512

// ====================ROS shit=========================================
extern NodeHandle nh;

// msgs
extern std_msgs::Float32 superior_right_shoulder_pos_msg;
extern std_msgs::Float32 superior_left_shoulder_pos_msg;
extern std_msgs::Float32 inferior_right_shoulder_pos_msg;
extern std_msgs::Float32 inferior_left_shoulder_pos_msg;

extern std_msgs::Float32 superior_right_arm_pos_msg;
extern std_msgs::Float32 superior_left_arm_pos_msg;
extern std_msgs::Float32 inferior_right_arm_pos_msg;
extern std_msgs::Float32 inferior_left_arm_pos_msg;

extern std_msgs::Float32 superior_right_forearm_pos_msg;
extern std_msgs::Float32 superior_left_forearm_pos_msg;
extern std_msgs::Float32 inferior_right_forearm_pos_msg;
extern std_msgs::Float32 inferior_left_forearm_pos_msg;

//extern ros::Publisher publisher;

// init
void initROS();

// callbacks
void superior_right_shoulder_abductor_cb(const std_msgs::Float32 &superior_right_shoulder_pos_msg);
void superior_left_shoulder_abductor_cb(const std_msgs::Float32 &superior_left_shoulder_pos_msg);
void inferior_right_shoulder_abductor_cb(const std_msgs::Float32 &inferior_right_shoulder_pos_msg);
void inferior_left_shoulder_abductor_cb(const std_msgs::Float32 &inferior_left_shoulder_pos_msg);

void superior_right_arm_extensor_cb(const std_msgs::Float32 &superior_right_arm_pos_msg);
void superior_left_arm_extensor_cb(const std_msgs::Float32 &superior_left_arm_pos_msg);
void inferior_right_arm_extensor_cb(const std_msgs::Float32 &inferior_right_arm_pos_msg);
void inferior_left_arm_extensor_cb(const std_msgs::Float32 &inferior_left_arm_pos_msg);

void superior_right_forearm_extensor_cb(const std_msgs::Float32 &superior_right_forearm_pos_msg);
void superior_left_forearm_extensor_cb(const std_msgs::Float32 &superior_left_forearm_pos_msg);
void inferior_right_forearm_extensor_cb(const std_msgs::Float32 &inferior_right_forearm_pos_msg);
void inferior_left_forearm_extensor_cb(const std_msgs::Float32 &inferior_left_forearm_pos_msg);



#endif  // INCLUDE_ROS_CONNECT_H