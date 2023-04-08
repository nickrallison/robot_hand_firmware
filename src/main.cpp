#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ros.h>

#include "robot_constant.h"
#include "motor_drive.h"
#include "ros_connect.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

double thumb_flex_pos = 1.0;
double thumb_abd_pos = 0.0;
double index_flex_pos = 1.0;
double index_abd_pos = 0.0;
double middle_flex_pos = 1.0;
double middle_abd_pos = 0.0;
double ring_flex_pos = 1.0;
double ring_abd_pos = 0.0;
double pinky_flex_pos = 1.0;
double pinky_abd_pos = 0.0;
double wrist_flex_pos = 1.0;

double thumb_flex_pos_prev = 1.0;
double thumb_abd_pos_prev = 0.0;
double index_flex_pos_prev = 1.0;
double index_abd_pos_prev = 0.0;
double middle_flex_pos_prev = 1.0;
double middle_abd_pos_prev = 0.0;
double ring_flex_pos_prev = 1.0;
double ring_abd_pos_prev = 0.0;
double pinky_flex_pos_prev = 1.0;
double pinky_abd_pos_prev = 0.0;
double wrist_flex_pos_prev = 1.0;

double thumb_flex_pos_next = 1.0;
double thumb_abd_pos_next = 0.0;
double index_flex_pos_next = 1.0;
double index_abd_pos_next = 0.0;
double middle_flex_pos_next = 1.0;
double middle_abd_pos_next = 0.0;
double ring_flex_pos_next = 1.0;
double ring_abd_pos_next = 0.0;
double pinky_flex_pos_next = 1.0;
double pinky_abd_pos_next = 0.0;
double wrist_flex_pos_next = 1.0;

double thumb_flex_min_pos = 0.0;
double thumb_abd_min_pos = -1.0;
double index_flex_min_pos = 0.0;
double index_abd_min_pos = -1.0;
double middle_flex_min_pos = 0.0;
double middle_abd_min_pos = -1.0;
double ring_flex_min_pos = 0.0;
double ring_abd_min_pos = -1.0;
double pinky_flex_min_pos = 0.0;
double pinky_abd_min_pos = -1.0;
double wrist_flex_min_pos = 0.0;

double thumb_flex_max_pos = 1.0;
double thumb_abd_max_pos = 1.0;
double index_flex_max_pos = 1.0;
double index_abd_max_pos = 1.0;
double middle_flex_max_pos = 1.0;
double middle_abd_max_pos = 1.0;
double ring_flex_max_pos = 1.0;
double ring_abd_max_pos = 1.0;
double pinky_flex_max_pos = 1.0;
double pinky_abd_max_pos = 1.0;
double wrist_flex_max_pos = 1.0;

double thumb_flex_pwm = 0.0;
double thumb_abd_pwm = 0.0;
double index_flex_pwm = 0.0;
double index_abd_pwm = 0.0;
double middle_flex_pwm = 0.0;
double middle_abd_pwm = 0.0;
double ring_flex_pwm = 0.0;
double ring_abd_pwm = 0.0;
double pinky_flex_pwm = 0.0;
double pinky_abd_pwm = 0.0;
double wrist_flex_pwm = 0.0;

double thumb_flex_min_pwm = 600;
double thumb_abd_min_pwm = 150;
double index_flex_min_pwm = 600;
double index_abd_min_pwm = 150;
double middle_flex_min_pwm = 600;
double middle_abd_min_pwm = 150;
double ring_flex_min_pwm = 600;
double ring_abd_min_pwm = 150;
double pinky_flex_min_pwm = 600;
double pinky_abd_min_pwm = 150;
double wrist_flex_min_pwm = 150;

double thumb_flex_max_pwm = 150;
double thumb_abd_max_pwm = 600;
double index_flex_max_pwm = 150;
double index_abd_max_pwm = 600;
double middle_flex_max_pwm = 150;
double middle_abd_max_pwm = 600;
double ring_flex_max_pwm = 150;
double ring_abd_max_pwm = 600;
double pinky_flex_max_pwm = 150;
double pinky_abd_max_pwm = 600;
double wrist_flex_max_pwm = 600;

double freq = 30;
double sign_period = 2;
double percent_complete = 0;

void setup()
{
  // Serial.begin(115200);
  // nh.getHardware()->setBaud(115200);
  // Serial.println("Initting Serial");
  Serial.begin(9600);
  nh.getHardware()->setBaud(9600);

  init_motors();
  initROS();
}

void loop()
{

  nh.spinOnce();
  // percent_complete += 1. / (sign_period * freq);
  // hand_lerp();
  command_motors();
  // percent_msg.data = percent_complete;
  // percent_pub.publish(&percent_msg);
  // if (percent_complete > 1.)
  // {
  //   thumb_flex_pos_prev = thumb_flex_pos_next;
  //   thumb_abd_pos_prev = thumb_abd_pos_next;
  //   index_flex_pos_prev = index_flex_pos_next;
  //   index_abd_pos_prev = index_abd_pos_next;
  //   middle_flex_pos_prev = middle_flex_pos_next;
  //   middle_abd_pos_prev = middle_abd_pos_next;
  //   ring_flex_pos_prev = ring_flex_pos_next;
  //   ring_abd_pos_prev = ring_abd_pos_next;
  //   pinky_flex_pos_prev = pinky_flex_pos_next;
  //   pinky_abd_pos_prev = pinky_abd_pos_next;
  //   wrist_flex_pos_prev = wrist_flex_pos_next;
  //   percent_complete = 0;
  // }
  delay(1. / freq);
}