# Canis Minor Firmware

## Description:
This is the firmware used by AC Robotics' Canis Bot. Uses ROS to listen to motor command positions and move motors to those positions. Inverse kinematics and Gait done by RPi.

## Install Directions
1. Install ProjectIO in VScode
(Not mandatory but other people can help with the install in VSCode as opposed to other IDEs)

## Uses:
1. Driving Servo Motors

## Dependencies
- ROS 
- Adafruit Servo Driver Library

## Position Specification
Right:
- Describes side-to-side motion of digits
- Range of -1 to 1, where 1 is towards the pinky and -1 is towards the thumb

Flex:
- Describles bending and extending of digits
- Range of 0 to 1, where 1 is fully flexed and 0 is fully extended