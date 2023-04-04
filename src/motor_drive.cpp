#include "motor_drive.h"
#include "robot_constant.h"
#include "../include/ros_connect.h"
#include "../include/pin_map.h"

#define SERVO_FREQ 50

// See this lib: https://learn.adafruit.com/16-channel-pwm-servo-driver?view=all
//pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);  for ease of use

void init_motors() {

    pwm.begin();
    Serial.println("Initting Servo Driver");

    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(1000);  // Analog servos run at ~50 Hz updates

}

void command_motors() {

    thumb_flex_pwm  = map2(thumb_flex_pos,  thumb_flex_min_pos,  thumb_flex_max_pos,  thumb_flex_min_pwm,  thumb_flex_max_pwm);
    thumb_abd_pwm   = map2(thumb_abd_pos,   thumb_abd_min_pos,   thumb_abd_max_pos,   thumb_abd_min_pwm,   thumb_abd_max_pwm);

    index_flex_pwm  = map2(index_flex_pos,  index_flex_min_pos,  index_flex_max_pos,  index_flex_min_pwm,  index_flex_max_pwm);
    index_abd_pwm   = map2(index_abd_pos,   index_abd_min_pos,   index_abd_max_pos,   index_abd_min_pwm,   index_abd_max_pwm);

    middle_flex_pwm = map2(middle_flex_pos, middle_flex_min_pos, middle_flex_max_pos, middle_flex_min_pwm, middle_flex_max_pwm);
    middle_abd_pwm  = map2(middle_abd_pos,  middle_abd_min_pos,  middle_abd_max_pos,  middle_abd_min_pwm,  middle_abd_max_pwm);

    ring_flex_pwm   = map2(ring_flex_pos,   ring_flex_min_pos,   ring_flex_max_pos,   ring_flex_min_pwm,   ring_flex_max_pwm);
    ring_abd_pwm    = map2(ring_abd_pos,    ring_abd_min_pos,    ring_abd_max_pos,    ring_abd_min_pwm,    ring_abd_max_pwm);

    pinky_flex_pwm  = map2(pinky_flex_pos,  pinky_flex_min_pos,  pinky_flex_max_pos,  pinky_flex_min_pwm,  pinky_flex_max_pwm);
    pinky_abd_pwm   = map2(pinky_abd_pos,   pinky_abd_min_pos,   pinky_abd_max_pos,   pinky_abd_min_pwm,   pinky_abd_max_pwm);

    wrist_flex_pwm  = map2(wrist_flex_pos,  wrist_flex_min_pos,  wrist_flex_max_pos,  wrist_flex_min_pwm,  wrist_flex_max_pwm);

    pwm.setPWM(THUMB_FLEX, 0, thumb_flex_pwm);
    pwm.setPWM(THUMB_ABDUCT, 0, thumb_abd_pwm);

    pwm.setPWM(INDEX_FLEX, 0, index_flex_pwm);
    pwm.setPWM(INDEX_ABDUCT, 0, index_abd_pwm);

    pwm.setPWM(MIDDLE_FLEX, 0, middle_flex_pwm);
    pwm.setPWM(MIDDLE_ABDUCT, 0, middle_abd_pwm);

    pwm.setPWM(RING_FLEX, 0, ring_flex_pwm);
    pwm.setPWM(RING_ABDUCT, 0, ring_abd_pwm);

    pwm.setPWM(PINKIE_FLEX, 0, pinky_flex_pwm);
    pwm.setPWM(PINKIE_ABDUCT, 0, pinky_abd_pwm);

    pwm.setPWM(15, 0, wrist_flex_pwm);

}

void thumb_flex_cb(const std_msgs::Float64 &thumb_flex_msg) {
    thumb_flex_pos_next = thumb_flex_msg.data;
}
void thumb_abd_cb(const std_msgs::Float64 &thumb_abd_msg) {
    thumb_abd_pos_next = thumb_abd_msg.data;
}
void index_flex_cb(const std_msgs::Float64 &index_flex_msg) {
    index_flex_pos_next = index_flex_msg.data;
}
void index_abd_cb(const std_msgs::Float64 &index_abd_msg) {
    index_abd_pos_next = index_abd_msg.data;
}
void middle_flex_cb(const std_msgs::Float64 &middle_flex_msg) {
    middle_flex_pos_next = middle_flex_msg.data;
}
void middle_abd_cb(const std_msgs::Float64 &middle_abd_msg) {
    middle_abd_pos_next = middle_abd_msg.data;
}
void ring_flex_cb(const std_msgs::Float64 &ring_flex_msg) {
    ring_flex_pos_next = ring_flex_msg.data;
}
void ring_abd_cb(const std_msgs::Float64 &ring_abd_msg) {
    ring_abd_pos_next = ring_abd_msg.data;
}
void pinky_flex_cb(const std_msgs::Float64 &pinky_flex_msg) {
    pinky_flex_pos_next = pinky_flex_msg.data;
}
void pinky_abd_cb(const std_msgs::Float64 &pinky_abd_msg) {
    pinky_abd_pos_next = pinky_abd_msg.data;
}
void wrist_flex_cb(const std_msgs::Float64 &wrist_flex_msg) {
    wrist_flex_pos_next = wrist_flex_msg.data;
}


double map2(double input, double x1, double x2, double y1, double y2) {
    if (input <= x1) return y1;
    if (input >= x2) return y2;
    double slope = (y2 - y1) / (x2 - x1);
    return (slope * (input - x1) + y1);
}

double lerp(double x1, double x2, double input) {
    if (input <= 0) return x1;
    if (input >= 1) return x2;
    return (x1 + (x2-x1) * input);
}

void hand_lerp() {
    thumb_flex_pos = lerp(thumb_flex_pos_prev, thumb_flex_pos_next, percent_complete);
    thumb_abd_pos = lerp(thumb_abd_pos_prev, thumb_abd_pos_next, percent_complete);
    index_flex_pos = lerp(index_flex_pos_prev, index_flex_pos_next, percent_complete);
    index_abd_pos = lerp(index_abd_pos_prev, index_abd_pos_next, percent_complete);
    middle_flex_pos = lerp(middle_flex_pos_prev, middle_flex_pos_next, percent_complete);
    middle_abd_pos = lerp(middle_abd_pos_prev, middle_abd_pos_next, percent_complete);
    ring_flex_pos = lerp(ring_flex_pos_prev, ring_flex_pos_next, percent_complete);
    ring_abd_pos = lerp(ring_abd_pos_prev, ring_abd_pos_next, percent_complete);
    pinky_flex_pos = lerp(pinky_flex_pos_prev, pinky_flex_pos_next, percent_complete);
    pinky_abd_pos = lerp(pinky_abd_pos_prev, pinky_abd_pos_next, percent_complete);
    wrist_flex_pos = lerp(wrist_flex_pos_prev, wrist_flex_pos_next, percent_complete);
}