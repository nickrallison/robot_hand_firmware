#include <Servo.h>

#include "motor_drive.h"
#include "robot_constant.h"
#include "pin_map.h"

void init_motors() {
    superior_right_shoulder_abductor.attach(servo_pins[0]);  
    superior_left_shoulder_abductor.attach(servo_pins[1]);  
    inferior_right_shoulder_abductor.attach(servo_pins[2]);  
    inferior_left_shoulder_abductor.attach(servo_pins[3]);  

    superior_right_arm_extensor.attach(servo_pins[4]);  
    superior_left_arm_extensor.attach(servo_pins[5]);  
    inferior_right_arm_extensor.attach(servo_pins[6]);  
    inferior_left_arm_extensor.attach(servo_pins[7]);  

    superior_right_forearm_extensor.attach(servo_pins[8]);  
    superior_left_forearm_extensor.attach(servo_pins[9]);  
    inferior_right_forearm_extensor.attach(servo_pins[10]);  
    inferior_left_forearm_extensor.attach(servo_pins[11]);  
}

void command_motors() {
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
}