#include <Arduino.h>

#include "pin_map.h"
#include "robot_constant.h"
#include "kinematics.h"
#include "motor_drive.h"
#include "gait_shape.h"

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


// ####### Threads ########
// TimedAction moveLegsThread = TimedAction(1000,updateLegs);



Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

gaitShape gait;

double robot_height_desired = -0.17;

double front_joint_dist = 0.1;
double back_joint_dist = 0.1;
double side_joint_dist = 0.1;

double superior_right_shoulder_abductor_pos = 0;  // Stores servo position in degrees from 0 to 180
double superior_left_shoulder_abductor_pos = 20;  // Stores servo position in degrees from 0 to 180
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

double superior_right_shoulder_abductor_offset = -52; // Stores servo position offset in degrees from 0 to 180
double superior_left_shoulder_abductor_offset = 15;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_shoulder_abductor_offset = 70;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_shoulder_abductor_offset = 44;  // Stores servo position offset in degrees from 0 to 180

double superior_right_arm_extensor_offset = -13;  // Stores servo position offset in degrees from 0 to 180
double superior_left_arm_extensor_offset = -20;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_arm_extensor_offset = -13;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_arm_extensor_offset = 25;  // Stores servo position offset in degrees from 0 to 180

double superior_right_forearm_extensor_offset = -110;  // Stores servo position offset in degrees from 0 to 180
double superior_left_forearm_extensor_offset = 204;  // Stores servo position offset in degrees from 0 to 180
double inferior_right_forearm_extensor_offset = -179;  // Stores servo position offset in degrees from 0 to 180
double inferior_left_forearm_extensor_offset = 153;  // Stores servo position offset in degrees from 0 to 180

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
  Serial.println("Initting");
  init_motors();
}

void loop() {
  //for (double z = 0; z < 2*M_PI; z += 0.1) {
    /* Serial.print("(");
    Serial.print(inferior_left_x);
    Serial.print(", ");
    Serial.print(inferior_left_y);
    Serial.print(", ");
    Serial.print(inferior_left_z);
    Serial.println(")");
    inferior_left_x = 0.0;
    inferior_left_y = 0.055;
    inferior_left_z = -0.12 + 0.05 * sin(z);*/


    //ik();
    /*superior_right_shoulder_abductor_pos = 0;
    superior_left_shoulder_abductor_pos = 0;
    inferior_right_shoulder_abductor_pos = 0;
    inferior_left_shoulder_abductor_pos = 0;

    superior_right_arm_extensor_pos = 0;
    superior_left_arm_extensor_pos = 0;
    inferior_right_arm_extensor_pos = 0;
    inferior_left_arm_extensor_pos = 0;

    superior_right_forearm_extensor_pos = 0;
    superior_left_forearm_extensor_pos = 0;
    inferior_right_forearm_extensor_pos = 0;
    inferior_left_forearm_extensor_pos = 0;*/

    command_motors();
    
    Serial.print("Sup Right shoulder ");
    Serial.println(superior_right_shoulder_abductor_pwm);
    Serial.print("Sup Left shoulder ");
    Serial.println(superior_left_shoulder_abductor_pwm);
    Serial.print("Inf Right shoulder ");
    Serial.println(inferior_right_shoulder_abductor_pwm);
    Serial.print("Inf Left shoulder ");
    Serial.println(inferior_left_shoulder_abductor_pwm);

    Serial.print("Sup Right arm ");
    Serial.println(superior_right_arm_extensor_pwm);
    Serial.print("Sup Left arm ");
    Serial.println(superior_left_arm_extensor_pwm);
    Serial.print("Inf Right arm ");
    Serial.println(inferior_right_arm_extensor_pwm);
    Serial.print("Inf Left arm ");
    Serial.println(inferior_left_arm_extensor_pwm);

    Serial.print("Sup Right forearm ");
    Serial.println(superior_right_forearm_extensor_pwm);
    Serial.print("Sup Left forearm ");
    Serial.println(superior_left_forearm_extensor_pwm);
    Serial.print("Inf Right forearm ");
    Serial.println(inferior_right_forearm_extensor_pwm);
    Serial.print("Inf Left forearm ");
    Serial.println(inferior_left_forearm_extensor_pwm);

    delay(50);

    //Serial.print('\n');


  //}
}