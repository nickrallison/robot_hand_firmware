#include <Servo.h>

extern Servo superior_right_shoulder_abductor;  // create servo object to control a servo
extern Servo superior_left_shoulder_abductor;  // create servo object to control a servo
extern Servo inferior_right_shoulder_abductor;  // create servo object to control a servo
extern Servo inferior_left_shoulder_abductor;  // create servo object to control a servo

extern Servo superior_right_arm_extensor;  // create servo object to control a servo
extern Servo superior_left_arm_extensor;  // create servo object to control a servo
extern Servo inferior_right_arm_extensor;  // create servo object to control a servo
extern Servo inferior_left_arm_extensor;  // create servo object to control a servo

extern Servo superior_right_forearm_extensor;  // create servo object to control a servo
extern Servo superior_left_forearm_extensor;  // create servo object to control a servo
extern Servo inferior_right_forearm_extensor;  // create servo object to control a servo
extern Servo inferior_left_forearm_extensor;  // create servo object to control a servo


extern int superior_right_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
extern int superior_left_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
extern int inferior_right_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180
extern int inferior_left_shoulder_abductor_pos;  // Stores servo position in degrees from 0 to 180

extern int superior_right_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern int superior_left_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern int inferior_right_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern int inferior_left_arm_extensor_pos;  // Stores servo position in degrees from 0 to 180

extern int superior_right_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern int superior_left_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern int inferior_right_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180
extern int inferior_left_forearm_extensor_pos;  // Stores servo position in degrees from 0 to 180

extern int superior_right_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int superior_left_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int inferior_right_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int inferior_left_shoulder_abductor_offset;  // Stores servo position offset in degrees from 0 to 180

extern int superior_right_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int superior_left_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int inferior_right_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int inferior_left_arm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180

extern int superior_right_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int superior_left_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int inferior_right_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180
extern int inferior_left_forearm_extensor_offset;  // Stores servo position offset in degrees from 0 to 180

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

