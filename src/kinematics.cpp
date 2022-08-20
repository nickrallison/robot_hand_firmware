#include "kinematics.h"
#include "robot_constant.h"
#include <math.h>

#define DEG_TO_RAD M_PI / 180.0

void ik() {
    double superior_right_d_param = (superior_right_x * superior_right_x + superior_right_y * superior_right_y - shoulder_length * shoulder_length + superior_right_z * superior_right_z - arm_length * arm_length - forearm_length * forearm_length) / (2 * arm_length * forearm_length);
    double superior_left_d_param = (superior_left_x * superior_left_x + superior_left_y * superior_left_y - shoulder_length * shoulder_length + superior_left_z * superior_left_z - arm_length * arm_length - forearm_length * forearm_length) / (2 * arm_length * forearm_length);
    double inferior_right_d_param = (inferior_right_x * inferior_right_x + inferior_right_y * inferior_right_y - shoulder_length * shoulder_length + inferior_right_z * inferior_right_z - arm_length * arm_length - forearm_length * forearm_length) / (2 * arm_length * forearm_length);
    double inferior_left_d_param = (inferior_left_x * inferior_left_x + inferior_left_y * inferior_left_y - shoulder_length * shoulder_length + inferior_left_z * inferior_left_z - arm_length * arm_length - forearm_length * forearm_length) / (2 * arm_length * forearm_length);

    superior_right_forearm_extensor_pos = atan2(sqrt(1 - superior_right_d_param * superior_right_d_param), superior_right_d_param); 
    superior_left_forearm_extensor_pos = atan2(sqrt(1 - superior_left_d_param * superior_left_d_param), superior_left_d_param); 
    inferior_right_forearm_extensor_pos = atan2(sqrt(1 - inferior_right_d_param * inferior_right_d_param), inferior_right_d_param); 
    inferior_left_forearm_extensor_pos = atan2(sqrt(1 - inferior_left_d_param * inferior_left_d_param), inferior_left_d_param); 

    superior_right_arm_extensor_pos = atan2(superior_right_z, sqrt(superior_right_x * superior_right_x + superior_right_y * superior_right_y - shoulder_length * shoulder_length)) - atan2(forearm_length * sin(superior_right_forearm_extensor_pos * DEG_TO_RAD), arm_length + forearm_length * cos(superior_right_forearm_extensor_pos * DEG_TO_RAD));
    superior_left_arm_extensor_pos = atan2(superior_left_z, sqrt(superior_left_x * superior_left_x + superior_left_y * superior_left_y - shoulder_length * shoulder_length)) - atan2(forearm_length * sin(superior_left_forearm_extensor_pos * DEG_TO_RAD), arm_length + forearm_length * cos(superior_left_forearm_extensor_pos * DEG_TO_RAD));
    inferior_right_arm_extensor_pos = atan2(inferior_right_z, sqrt(inferior_right_x * inferior_right_x + inferior_right_y * inferior_right_y - shoulder_length * shoulder_length)) - atan2(forearm_length * sin(inferior_right_forearm_extensor_pos * DEG_TO_RAD), arm_length + forearm_length * cos(inferior_right_forearm_extensor_pos * DEG_TO_RAD));
    inferior_left_arm_extensor_pos = atan2(inferior_left_z, sqrt(inferior_left_x * inferior_left_x + inferior_left_y * inferior_left_y - shoulder_length * shoulder_length)) - atan2(forearm_length * sin(inferior_left_forearm_extensor_pos * DEG_TO_RAD), arm_length + forearm_length * cos(inferior_left_forearm_extensor_pos * DEG_TO_RAD));

    superior_right_shoulder_abductor_pos = -atan2(-superior_right_y, superior_right_x) - atan2(sqrt(superior_right_x * superior_right_x + superior_right_y * superior_right_y - shoulder_length * shoulder_length), -shoulder_length);
    superior_left_shoulder_abductor_pos = -atan2(-superior_left_y, superior_left_x) - atan2(sqrt(superior_left_x * superior_left_x + superior_left_y * superior_left_y - shoulder_length * shoulder_length), -shoulder_length);
    inferior_right_shoulder_abductor_pos = -atan2(-inferior_right_y, inferior_right_x) - atan2(sqrt(inferior_right_x * inferior_right_x + inferior_right_y * sinferiorright_y - shoulder_length * shoulder_length), -shoulder_length);
    inferior_left_shoulder_abductor_pos = -atan2(-inferior_left_y, inferior_left_x) - atan2(sqrt(inferior_left_x * inferior_left_x + inferior_left_y * inferior_left_y - shoulder_length * shoulder_length), -shoulder_length);
}

void fk() {

}