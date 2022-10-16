#include "../include/ros_connect.h"

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float64.h>
#include <tf/tf.h>

NodeHandle nh;

std_msgs::Float64 superior_right_shoulder_pos_msg;
std_msgs::Float64 superior_left_shoulder_pos_msg;
std_msgs::Float64 inferior_right_shoulder_pos_msg;
std_msgs::Float64 inferior_left_shoulder_pos_msg;

std_msgs::Float64 superior_right_arm_pos_msg;
std_msgs::Float64 superior_left_arm_pos_msg;
std_msgs::Float64 inferior_right_arm_pos_msg;
std_msgs::Float64 inferior_left_arm_pos_msg;

std_msgs::Float64 superior_right_forearm_pos_msg;
std_msgs::Float64 superior_left_forearm_pos_msg;
std_msgs::Float64 inferior_right_forearm_pos_msg;
std_msgs::Float64 inferior_left_forearm_pos_msg;



//ros::Publisher debugPub("/teensy/debug", &printDebug);

ros::Subscriber<std_msgs::Float64> superior_right_shoulder_abductor_sub("/actuation/superior/right/shoulder", &superior_right_shoulder_abductor_cb);
ros::Subscriber<std_msgs::Float64> superior_left_shoulder_abductor_sub("/actuation/superior/left/shoulder", &superior_left_shoulder_abductor_cb);
ros::Subscriber<std_msgs::Float64> inferior_right_shoulder_abductor_sub("/actuation/inferior/right/shoulder", &inferior_right_shoulder_abductor_cb);
ros::Subscriber<std_msgs::Float64> inferior_left_shoulder_abductor_sub("/actuation/inferior/left/shoulder", &inferior_left_shoulder_abductor_cb);

ros::Subscriber<std_msgs::Float64> superior_right_arm_extensor_sub("/actuation/superior/right/arm", &superior_right_arm_extensor_cb);
ros::Subscriber<std_msgs::Float64> superior_left_arm_extensor_sub("/actuation/superior/left/arm", &superior_left_arm_extensor_cb);
ros::Subscriber<std_msgs::Float64> inferior_right_arm_extensor_sub("/actuation/inferior/right/arm", &inferior_right_arm_extensor_cb);
ros::Subscriber<std_msgs::Float64> inferior_left_arm_extensor_sub("/actuation/inferior/left/arm", &inferior_left_arm_extensor_cb);

ros::Subscriber<std_msgs::Float64> superior_right_forearm_extensor_sub("/actuation/superior/right/forearm", &superior_right_forearm_extensor_cb);
ros::Subscriber<std_msgs::Float64> superior_left_forearm_extensor_sub("/actuation/superior/left/forearm", &superior_left_forearm_extensor_cb);
ros::Subscriber<std_msgs::Float64> inferior_right_forearm_extensor_sub("/actuation/inferior/right/forearm", &inferior_right_forearm_extensor_cb);
ros::Subscriber<std_msgs::Float64> inferior_left_forearm_extensor_sub("/actuation/inferior/left/forearm", &inferior_left_forearm_extensor_cb);
    

void superior_right_shoulder_abductor_cb(const std_msgs::Float64 &superior_right_shoulder_pos_msg);
void superior_left_shoulder_abductor_cb(const std_msgs::Float64 &superior_left_shoulder_pos_msg);
void inferior_right_shoulder_abductor_cb(const std_msgs::Float64 &inferior_right_shoulder_pos_msg);
void inferior_left_shoulder_abductor_cb(const std_msgs::Float64 &inferior_left_shoulder_pos_msg);

void superior_right_arm_extensor_cb(const std_msgs::Float64 &superior_right_arm_pos_msg);
void superior_left_arm_extensor_cb(const std_msgs::Float64 &superior_left_arm_pos_msg);
void inferior_right_arm_extensor_cb(const std_msgs::Float64 &inferior_right_arm_pos_msg);
void inferior_left_arm_extensor_cb(const std_msgs::Float64 &inferior_left_arm_pos_msg);

void superior_right_forearm_extensor_cb(const std_msgs::Float64 &superior_right_forearm_pos_msg);
void superior_left_forearm_extensor_cb(const std_msgs::Float64 &superior_left_forearm_pos_msg);
void inferior_right_forearm_extensor_cb(const std_msgs::Float64 &inferior_right_forearm_pos_msg);
void inferior_left_forearm_extensor_cb(const std_msgs::Float64 &inferior_left_forearm_pos_msg);


void initROS() {
  nh.initNode();
  //sub
  nh.subscribe(superior_right_shoulder_abductor_sub);
  nh.subscribe(superior_left_shoulder_abductor_sub);
  nh.subscribe(inferior_right_shoulder_abductor_sub);
  nh.subscribe(inferior_left_shoulder_abductor_sub);

  nh.subscribe(superior_right_arm_extensor_sub);
  nh.subscribe(superior_left_arm_extensor_sub);
  nh.subscribe(inferior_right_arm_extensor_sub);
  nh.subscribe(inferior_left_arm_extensor_sub);

  nh.subscribe(superior_right_forearm_extensor_sub);
  nh.subscribe(superior_left_forearm_extensor_sub);
  nh.subscribe(inferior_right_forearm_extensor_sub);
  nh.subscribe(inferior_left_forearm_extensor_sub);
  // pub
  //nh.advertise(debugPub);
  // give serial_node.py a chance to get to know the topics
  nh.negotiateTopics();

}