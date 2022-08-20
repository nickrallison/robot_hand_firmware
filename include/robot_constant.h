#include <Servo.h>

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


int superior_right_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
int superior_left_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
int inferior_right_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
int inferior_left_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180

int superior_right_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
int superior_left_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
int inferior_right_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
int inferior_left_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180

int superior_right_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
int superior_left_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
int inferior_right_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
int inferior_left_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180

int superior_right_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
int superior_left_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
int inferior_right_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
int inferior_left_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180

int superior_right_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
int superior_left_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
int inferior_right_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
int inferior_left_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180

int superior_right_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
int superior_left_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
int inferior_right_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
int inferior_left_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180

double superior_right_x;    // Stores bot legs x, y, & z positions for each leg
double superior_right_y;    // Stores bot legs x, y, & z positions for each leg
double superior_right_z;    // Stores bot legs x, y, & z positions for each leg

double superior_left_x;     // Stores bot legs x, y, & z positions for each leg
double superior_left_y;     // Stores bot legs x, y, & z positions for each leg
double superior_left_z;     // Stores bot legs x, y, & z positions for each leg

double inferior_right_x;    // Stores bot legs x, y, & z positions for each leg
double inferior_right_y;    // Stores bot legs x, y, & z positions for each leg
double inferior_right_z;    // Stores bot legs x, y, & z positions for each leg

double inferior_left_x;     // Stores bot legs x, y, & z positions for each leg
double inferior_left_y;     // Stores bot legs x, y, & z positions for each leg
double inferior_left_z;     // Stores bot legs x, y, & z positions for each leg
