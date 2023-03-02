#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "robot_constant.h"
#include "motor_drive.h"
#include "ros_connect.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

double thumb_flex_pos = 0.0;
double thumb_abd_pos = 0.0;
double index_flex_pos = 0.0;
double index_abd_pos = 0.0;
double middle_flex_pos = 0.0;
double middle_abd_pos = 0.0;
double ring_flex_pos = 0.0;
double ring_abd_pos = 0.0;
double pinky_flex_pos = 0.0;
double pinky_abd_pos = 0.0;
double wrist_flex_pos = 0.0;

double thumb_flex_min_pos = 0.0;
double thumb_abd_min_pos = 0.0;
double index_flex_min_pos = 0.0;
double index_abd_min_pos = 0.0;
double middle_flex_min_pos = 0.0;
double middle_abd_min_pos = 0.0;
double ring_flex_min_pos = 0.0;
double ring_abd_min_pos = 0.0;
double pinky_flex_min_pos = 0.0;
double pinky_abd_min_pos = 0.0;
double wrist_flex_min_pos = 0.0;

double thumb_flex_max_pos = 0.0;
double thumb_abd_max_pos = 0.0;
double index_flex_max_pos = 0.0;
double index_abd_max_pos = 0.0;
double middle_flex_max_pos = 0.0;
double middle_abd_max_pos = 0.0;
double ring_flex_max_pos = 0.0;
double ring_abd_max_pos = 0.0;
double pinky_flex_max_pos = 0.0;
double pinky_abd_max_pos = 0.0;
double wrist_flex_max_pos = 0.0;

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

double thumb_flex_min_pwm = 0.0;
double thumb_abd_min_pwm = 0.0;
double index_flex_min_pwm = 0.0;
double index_abd_min_pwm = 0.0;
double middle_flex_min_pwm = 0.0;
double middle_abd_min_pwm = 0.0;
double ring_flex_min_pwm = 0.0;
double ring_abd_min_pwm = 0.0;
double pinky_flex_min_pwm = 0.0;
double pinky_abd_min_pwm = 0.0;
double wrist_flex_min_pwm = 0.0;

double thumb_flex_max_pwm = 0.0;
double thumb_abd_max_pwm = 0.0;
double index_flex_max_pwm = 0.0;
double index_abd_max_pwm = 0.0;
double middle_flex_max_pwm = 0.0;
double middle_abd_max_pwm = 0.0;
double ring_flex_max_pwm = 0.0;
double ring_abd_max_pwm = 0.0;
double pinky_flex_max_pwm = 0.0;
double pinky_abd_max_pwm = 0.0;
double wrist_flex_max_pwm = 0.0;


void setup() {
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  Serial.println("Initting Serial");
  init_motors();
  initROS();
}

void loop() {

  nh.spinOnce();
  command_motors();

}