#include <Arduino.h>

#include "pin_map.h"
#include "robot_constant.h"
#include "kinematics.h"
#include "motor_drive.h"
#include "ros_connect.h"
#include "multithreading.h"
#include "access_point.h"

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <TimedAction.h>



/* This is the main file for the CANIS_mini arduino controller
 *  
 * ####### Notes #######
 * Inverse Kinematics:
 * In regards to inverse kinematics, a research paper is linked containing the formulas used for IK, see documents/Inverse-Kinematic-Analysis-Of-A-Quadruped-Robot.pdf
 * 1. shoulder_abductor position is angle from the plane of base_link (robot body frame)
 * 2. arm_extensor position is angle forwards from the z unit vector relative to the xy plane through base_link
 * 3. forearm_extensor position is angle backwards from line through the arm joint
 * 
 */ 

//Threads
TimedAction wifiThread = TimedAction(1000,wifiCheck);

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

double superior_right_shoulder_abductor_pos = 0;
double superior_left_shoulder_abductor_pos = 0;
double inferior_right_shoulder_abductor_pos = 0;
double inferior_left_shoulder_abductor_pos = 0;

double superior_right_arm_extensor_pos = 1.45;
double superior_left_arm_extensor_pos = 1.45;
double inferior_right_arm_extensor_pos = 1.45;
double inferior_left_arm_extensor_pos = 1.45;

double superior_right_forearm_extensor_pos = 2.32;
double superior_left_forearm_extensor_pos = 2.32;
double inferior_right_forearm_extensor_pos = 2.32;
double inferior_left_forearm_extensor_pos = 2.32;

double superior_right_shoulder_abductor_offset = -50; // Stores servo position offset in degrees from 0 to 180
double superior_left_shoulder_abductor_offset = 20;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_shoulder_abductor_offset = 65;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_shoulder_abductor_offset = 45;  // Stores servo position offset in degrees from 0 to 180

double superior_right_arm_extensor_offset = -20;  // Stores servo position offset in degrees from 0 to 180
double superior_left_arm_extensor_offset = -15;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_arm_extensor_offset = -10;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_arm_extensor_offset = 10;  // Stores servo position offset in degrees from 0 to 180

double superior_right_forearm_extensor_offset = -110;  // Stores servo position offset in degrees from 0 to 180
double superior_left_forearm_extensor_offset = 204;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_forearm_extensor_offset = -165;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_forearm_extensor_offset = 160;  // Stores servo position offset in degrees from 0 to 180

int superior_right_shoulder_abductor_pwm = 0;
int superior_left_shoulder_abductor_pwm = 0;
int inferior_right_shoulder_abductor_pwm = 0;
int inferior_left_shoulder_abductor_pwm = 0;

int superior_right_arm_extensor_pwm = 0;
int superior_left_arm_extensor_pwm = 0;
int inferior_right_arm_extensor_pwm = 0;
int inferior_left_arm_extensor_pwm = 0;

int superior_right_forearm_extensor_pwm = 0;
int superior_left_forearm_extensor_pwm = 0;
int inferior_right_forearm_extensor_pwm = 0;
int inferior_left_forearm_extensor_pwm = 0;

double superior_right_x = 0;
double superior_right_y = 0.055;
double superior_right_z = -0.15;

double superior_left_x = 0; 
double superior_left_y = 0.055; 
double superior_left_z = -0.15; 

double inferior_right_x = -0.05;
double inferior_right_y = 0.055;
double inferior_right_z = -0.15;

double inferior_left_x = -0.05; 
double inferior_left_y = 0.055; 
double inferior_left_z = -0.15; 


double shoulder_length = 0.055;
double arm_length = 0.105;
double forearm_length = 0.136;

void setup() {
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  Serial.println("Initting");
  init_motors();
  initROS();
  initWifi();
  debug_msg.data = "Test";
}

void loop() {

  /*for (double z = 0; z < 2 * M_PI; z += 0.01) {
    superior_right_z = -0.15 + 0.05 * sin(z);
    superior_left_z = -0.15 + 0.05 * sin(z);
    inferior_right_z = -0.15 + 0.05 * sin(z);
    inferior_left_z = -0.15 + 0.05 * sin(z);
    ik();
    command_motors();
    delay(0.1);
  }*/
  debugPub.publish(&debug_msg);
  nh.spinOnce();

  //wifiThread.check();
}