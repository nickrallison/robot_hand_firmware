#include <Arduino.h>
#include <Servo.h>

#include "pin_map.h"
#include "robot_constant.h"
#include "kinematics.h"
#include "motor_drive.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

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

/*
Servo superior_right_shoulder_abductor;  // create servo object to control a servo
Servo superior_left_shoulder_abductor;  // create servo object to control a servo
Servo inferior_right_shoulder_abductor;  // create servo object to control a servo
Servo inferior_left_shoulder_abductor;  // create servo object to control a servo

Servo superior_right_arm_extensor;  // create servo object to control a servo
Servo superior_left_arm_extensor;  // create servo object to control a servo
Servo inferior_right_arm_extensor;  // create servo object to control a servo
Servo inferior_left_arm_extensor;  // create servo object to control a servo

Servo superior_right_forearm_extensor;  // create servo object to control a servo
Servo superior_left_forearm_extensor;  // create servo object to control a servo
Servo inferior_right_forearm_extensor;  // create servo object to control a servo
Servo inferior_left_forearm_extensor;  // create servo object to control a servo
*/

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


double superior_right_shoulder_abductor_pos = 0;  // Stores servo position in degrees from 0 to 180
double superior_left_shoulder_abductor_pos = 0;  // Stores servo position in degrees from 0 to 180
double inferior_right_shoulder_abductor_pos = 0;  // Stores servo position in degrees from 0 to 180
double inferior_left_shoulder_abductor_pos = 0;  // Stores servo position in degrees from 0 to 180

double superior_right_arm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180
double superior_left_arm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180
double inferior_right_arm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180
double inferior_left_arm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180

double superior_right_forearm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180
double superior_left_forearm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180
double inferior_right_forearm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180
double inferior_left_forearm_extensor_pos = 0;  // Stores servo position in degrees from 0 to 180

double superior_right_shoulder_abductor_offset = 0; // Stores servo position offset in degrees from 0 to 180
double superior_left_shoulder_abductor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_shoulder_abductor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_shoulder_abductor_offset = 0;  // Stores servo position offset in degrees from 0 to 180

double superior_right_arm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double superior_left_arm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_arm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_arm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180

double superior_right_forearm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double superior_left_forearm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_forearm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_forearm_extensor_offset = 0;  // Stores servo position offset in degrees from 0 to 180

int superior_right_shoulder_abductor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int superior_left_shoulder_abductor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int inferior_right_shoulder_abductor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int inferior_left_shoulder_abductor_pwm = 0;  // Stores servo position in degrees from 0 to 180

int superior_right_arm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int superior_left_arm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int inferior_right_arm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int inferior_left_arm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180

int superior_right_forearm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int superior_left_forearm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int inferior_right_forearm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180
int inferior_left_forearm_extensor_pwm = 0;  // Stores servo position in degrees from 0 to 180

double superior_right_x = 0;    // Stores bot legs x, y, & z positions for each leg
double superior_right_y = 0;    // Stores bot legs x, y, & z positions for each leg
double superior_right_z = 0;    // Stores bot legs x, y, & z positions for each leg

double superior_left_x = 0;     // Stores bot legs x, y, & z positions for each leg
double superior_left_y = 0;     // Stores bot legs x, y, & z positions for each leg
double superior_left_z = 0;     // Stores bot legs x, y, & z positions for each leg

double inferior_right_x = 0;    // Stores bot legs x, y, & z positions for each leg
double inferior_right_y = 0;    // Stores bot legs x, y, & z positions for each leg
double inferior_right_z = 0;    // Stores bot legs x, y, & z positions for each leg

double inferior_left_x = 0;     // Stores bot legs x, y, & z positions for each leg
double inferior_left_y = 0;     // Stores bot legs x, y, & z positions for each leg
double inferior_left_z = 0;     // Stores bot legs x, y, & z positions for each leg

// Canis Body Params, measure from joint center
double canis_length = 0.215;
double canis_width = 0.23;

double shoulder_length = 0.055;
double arm_length = 0.105;
double forearm_length = 0.136;

// myservo.write(pos); // To drive servo, must add in delay, amount tbd

void setup() {
  Serial.begin(9600);
  init_motors();
}

void loop() {
  for (double z = 0; z < 2*M_PI; z += 0.1) {
    //Serial.print(x);
    superior_right_x = 0.0;
    superior_right_y = 0.055;
    superior_right_z = -0.12 + 0.05 * sin(z);
    ik();
    command_motors();
    delay(50);

    //Serial.print(superior_right_z);
    //Serial.print('\n');


  }
}