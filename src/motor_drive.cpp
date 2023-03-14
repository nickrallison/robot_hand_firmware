#include "motor_drive.h"
#include "robot_constant.h"
#include "../include/ros_connect.h"

#define SERVOMIN  60 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  520 // This is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates



// See this lib: https://learn.adafruit.com/16-channel-pwm-servo-driver?view=all
//pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);  for ease of use

void init_motors() {

    pwm.begin();
    Serial.println("Initting Servo Driver");
    pwm.setOscillatorFrequency(27000000); //set w/ ossicloscope?
    pwm.setPWMFreq(SERVO_FREQ);

}

void command_motors() {

    thumb_flex_pwm  = map2(thumb_flex_pos,  thumb_flex_min_pos,  thumb_flex_max_pos,  thumb_flex_min_pwm,  thumb_flex_max_pwm);
    thumb_right_pwm   = map2(thumb_right_pos,   thumb_right_min_pos,   thumb_right_max_pos,   thumb_right_min_pwm,   thumb_right_max_pwm);

    index_flex_pwm  = map2(index_flex_pos,  index_flex_min_pos,  index_flex_max_pos,  index_flex_min_pwm,  index_flex_max_pwm);
    index_right_pwm   = map2(index_right_pos,   index_right_min_pos,   index_right_max_pos,   index_right_min_pwm,   index_right_max_pwm);

    middle_flex_pwm = map2(middle_flex_pos, middle_flex_min_pos, middle_flex_max_pos, middle_flex_min_pwm, middle_flex_max_pwm);
    middle_right_pwm  = map2(middle_right_pos,  middle_right_min_pos,  middle_right_max_pos,  middle_right_min_pwm,  middle_right_max_pwm);

    ring_flex_pwm   = map2(ring_flex_pos,   ring_flex_min_pos,   ring_flex_max_pos,   ring_flex_min_pwm,   ring_flex_max_pwm);
    ring_right_pwm    = map2(ring_right_pos,    ring_right_min_pos,    ring_right_max_pos,    ring_right_min_pwm,    ring_right_max_pwm);

    pinky_flex_pwm  = map2(pinky_flex_pos,  pinky_flex_min_pos,  pinky_flex_max_pos,  pinky_flex_min_pwm,  pinky_flex_max_pwm);
    pinky_right_pwm   = map2(pinky_right_pos,   pinky_right_min_pos,   pinky_right_max_pos,   pinky_right_min_pwm,   pinky_right_max_pwm);

    wrist_flex_pwm  = map2(wrist_flex_pos,  wrist_flex_min_pos,  wrist_flex_max_pos,  wrist_flex_min_pwm,  wrist_flex_max_pwm);

    pwm.setPWM(0, 0, thumb_flex_pwm);
    pwm.setPWM(1, 0, thumb_right_pwm);

    pwm.setPWM(2, 0, index_flex_pwm);
    pwm.setPWM(3, 0, index_right_pwm);

    pwm.setPWM(4, 0, middle_flex_pwm);
    pwm.setPWM(5, 0, middle_right_pwm);

    pwm.setPWM(6, 0, ring_flex_pwm);
    pwm.setPWM(7, 0, ring_right_pwm);

    pwm.setPWM(8, 0, pinky_flex_pwm);
    pwm.setPWM(9, 0, pinky_right_pwm);

    pwm.setPWM(10, 0, wrist_flex_pwm);

}

void thumb_flex_cb(const std_msgs::Float64 &thumb_flex_msg) {
    thumb_flex_pos = thumb_flex_msg.data;
}
void thumb_right_cb(const std_msgs::Float64 &thumb_right_msg) {
    thumb_right_pos = thumb_right_msg.data;
}
void index_flex_cb(const std_msgs::Float64 &index_flex_msg) {
    index_flex_pos = index_flex_msg.data;
}
void index_right_cb(const std_msgs::Float64 &index_right_msg) {
    index_right_pos = index_right_msg.data;
}
void middle_flex_cb(const std_msgs::Float64 &middle_flex_msg) {
    middle_flex_pos = middle_flex_msg.data;
}
void middle_right_cb(const std_msgs::Float64 &middle_right_msg) {
    middle_right_pos = middle_right_msg.data;
}
void ring_flex_cb(const std_msgs::Float64 &ring_flex_msg) {
    ring_flex_pos = ring_flex_msg.data;
}
void ring_right_cb(const std_msgs::Float64 &ring_right_msg) {
    ring_right_pos = ring_right_msg.data;
}
void pinky_flex_cb(const std_msgs::Float64 &pinky_flex_msg) {
    pinky_flex_pos = pinky_flex_msg.data;
}
void pinky_right_cb(const std_msgs::Float64 &pinky_right_msg) {
    pinky_right_pos = pinky_right_msg.data;
}
void wrist_flex_cb(const std_msgs::Float64 &wrist_flex_msg) {
    wrist_flex_pos = wrist_flex_msg.data;
}


double map2(double input, double x1, double x2, double y1, double y2) {
    if (input <= x1) return y1;
    if (input >= x2) return y2;
    double slope = (y2 - y1) / (x2 - x1);
    return (slope * (input - x1) + y1);
}