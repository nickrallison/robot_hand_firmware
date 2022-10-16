
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include "gait_shape.h"
/*
superior_right_shoulder_abductor;
superior_left_shoulder_abductor;
inferior_right_shoulder_abductor;
inferior_left_shoulder_abductor;

superior_right_arm_extensor;
superior_left_arm_extensor;
inferior_right_arm_extensor;
inferior_left_arm_extensor;

superior_right_forearm_extensor;
superior_left_forearm_extensor;
inferior_right_forearm_extensor;
inferior_left_forearm_extensor;
*/

extern Adafruit_PWMServoDriver pwm;// = Adafruit_PWMServoDriver();

extern gaitShape gait;

extern double superior_right_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
extern double superior_left_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
extern double inferior_right_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
extern double inferior_left_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180

extern double superior_right_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern double superior_left_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern double inferior_right_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern double inferior_left_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180

extern double superior_right_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern double superior_left_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern double inferior_right_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern double inferior_left_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180

extern double superior_right_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double superior_left_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double inferior_right_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double inferior_left_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180

extern double superior_right_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double superior_left_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double inferior_right_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double inferior_left_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180

extern double superior_right_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double superior_left_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double inferior_right_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern double inferior_left_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 1pwm

extern int superior_right_shoulder_abductor_pwm;  // Stores servo position in degrees from 0 to 180
extern int superior_left_shoulder_abductor_pwm;  // Stores servo position in degrees from 0 to 180
extern int inferior_right_shoulder_abductor_pwm;  // Stores servo position in degrees from 0 to 180
extern int inferior_left_shoulder_abductor_pwm;  // Stores servo position in degrees from 0 to 180

extern int superior_right_arm_extensor_pwm;  // Stores servo position in degrees from 0 to 180
extern int superior_left_arm_extensor_pwm;  // Stores servo position in degrees from 0 to 180
extern int inferior_right_arm_extensor_pwm;  // Stores servo position in degrees from 0 to 180
extern int inferior_left_arm_extensor_pwm;  // Stores servo position in degrees from 0 to 180

extern int superior_right_forearm_extensor_pwm;  // Stores servo position in degrees from 0 to 180
extern int superior_left_forearm_extensor_pwm;  // Stores servo position in degrees from 0 to 180
extern int inferior_right_forearm_extensor_pwm;  // Stores servo position in degrees from 0 to 180
extern int inferior_left_forearm_extensor_pwm;  // Stores servo position in degrees from 0 to 180

extern double superior_right_x;    // Stores bot legs x, y, & z positions for each leg
extern double superior_right_y;    // Stores bot legs x, y, & z positions for each leg
extern double superior_right_z;    // Stores bot legs x, y, & z positions for each leg

extern double superior_left_x;     // Stores bot legs x, y, & z positions for each leg
extern double superior_left_y;     // Stores bot legs x, y, & z positions for each leg
extern double superior_left_z;     // Stores bot legs x, y, & z positions for each leg

extern double inferior_right_x;    // Stores bot legs x, y, & z positions for each leg
extern double inferior_right_y;    // Stores bot legs x, y, & z positions for each leg
extern double inferior_right_z;    // Stores bot legs x, y, & z positions for each leg

extern double inferior_left_x;     // Stores bot legs x, y, & z positions for each leg
extern double inferior_left_y;     // Stores bot legs x, y, & z positions for each leg
extern double inferior_left_z;     // Stores bot legs x, y, & z positions for each leg


extern double canis_length;
extern double canis_width;

extern double shoulder_length;
extern double arm_length;
extern double forearm_length;

