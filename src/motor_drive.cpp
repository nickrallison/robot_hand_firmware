#include <Servo.h>

#include "motor_drive.h"
#include "robot_constant.h"
#include "pin_map.h"

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

uint8_t servonum = 0;



// See this lib: https://learn.adafruit.com/16-channel-pwm-servo-driver?view=all
//pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);  for ease of use

void init_motors() {

    pwm.begin();

    pwm.setOscillatorFrequency(27000000); //set w/ ossicloscope?
    pwm.setPWMFreq(SERVO_FREQ);  
    

}

void command_motors() {

    superior_right_shoulder_abductor_pwm = map(superior_right_shoulder_abductor_pos + superior_right_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    superior_left_shoulder_abductor_pwm = map(superior_left_shoulder_abductor_pos + superior_left_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    inferior_right_shoulder_abductor_pwm = map(inferior_right_shoulder_abductor_pos + inferior_right_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    inferior_left_shoulder_abductor_pwm = map(inferior_left_shoulder_abductor_pos + inferior_left_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);

    superior_right_shoulder_abductor_pwm = map(superior_right_shoulder_abductor_pos + superior_right_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    superior_left_shoulder_abductor_pwm = map(superior_left_shoulder_abductor_pos + superior_left_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    inferior_right_shoulder_abductor_pwm = map(inferior_right_shoulder_abductor_pos + inferior_right_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    inferior_left_shoulder_abductor_pwm = map(inferior_left_shoulder_abductor_pos + inferior_left_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);

    superior_right_shoulder_abductor_pwm = map(superior_right_shoulder_abductor_pos + superior_right_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    superior_left_shoulder_abductor_pwm = map(superior_left_shoulder_abductor_pos + superior_left_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    inferior_right_shoulder_abductor_pwm = map(inferior_right_shoulder_abductor_pos + inferior_right_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);
    inferior_left_shoulder_abductor_pwm = map(inferior_left_shoulder_abductor_pos + inferior_left_shoulder_abductor_offset, 0, 180, SERVOMIN, SERVOMAX);


    pwm.setPWM(0, 0, superior_right_shoulder_abductor_pwm);
    pwm.setPWM(1, 0, superior_left_shoulder_abductor_pwm);
    pwm.setPWM(2, 0, inferior_right_shoulder_abductor_pwm);
    pwm.setPWM(3, 0, inferior_left_shoulder_abductor_pwm);

    pwm.setPWM(4, 0, superior_right_shoulder_abductor_pwm);
    pwm.setPWM(5, 0, superior_left_shoulder_abductor_pwm);
    pwm.setPWM(6, 0, inferior_right_shoulder_abductor_pwm);
    pwm.setPWM(7, 0, inferior_left_shoulder_abductor_pwm);

    pwm.setPWM(8, 0, superior_right_shoulder_abductor_pwm);
    pwm.setPWM(9, 0, superior_left_shoulder_abductor_pwm);
    pwm.setPWM(10, 0, inferior_right_shoulder_abductor_pwm);
    pwm.setPWM(11, 0, inferior_left_shoulder_abductor_pwm);
    

    // pwmfreq = map(deg, 0, 180, SERVOMIN, SERVOMAX);
    // For each servo

    /*
    superior_right_shoulder_abductor.write(superior_right_shoulder_abductor_pos + superior_right_shoulder_abductor_offset);  
    superior_left_shoulder_abductor.write(superior_left_shoulder_abductor_pos + superior_left_shoulder_abductor_offset);  
    inferior_right_shoulder_abductor.write(inferior_right_shoulder_abductor_pos + inferior_right_shoulder_abductor_offset);  
    inferior_left_shoulder_abductor.write(inferior_left_shoulder_abductor_pos + inferior_left_shoulder_abductor_offset);  

    superior_right_arm_extensor.write(superior_right_arm_extensor_pos + superior_right_arm_extensor_offset);  
    superior_left_arm_extensor.write(superior_left_arm_extensor_pos + superior_left_arm_extensor_offset);  
    inferior_right_arm_extensor.write(inferior_right_arm_extensor_pos + inferior_right_arm_extensor_offset);  
    inferior_left_arm_extensor.write(inferior_left_arm_extensor_pos + inferior_left_arm_extensor_offset);  

    superior_right_forearm_extensor.write(superior_right_forearm_extensor_pos + superior_right_forearm_extensor_offset);  
    superior_left_forearm_extensor.write(superior_left_forearm_extensor_pos + superior_left_forearm_extensor_offset);  
    inferior_right_forearm_extensor.write(inferior_right_forearm_extensor_pos + inferior_right_forearm_extensor_offset);  
    inferior_left_forearm_extensor.write(inferior_left_forearm_extensor_pos + inferior_left_forearm_extensor_offset);  
    */
}