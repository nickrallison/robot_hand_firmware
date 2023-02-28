#include <Arduino.h>

#include "pin_map.h"
#include "robot_constant.h"
#include "motor_drive.h"
#include "ros_connect.h"

#include <Wire.h>

#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


void setup() {
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  Serial.println("Initting");
  init_motors();
  initROS();
  initWifi();
  //debug_msg.data = "Test";
}

void loop() {

  nh.spinOnce();
  //pub_imu_raw();

}