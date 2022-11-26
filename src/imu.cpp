#include <Wire.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#include "robot_constant.h"
#include "ros_connect.h"

void pub_imu_raw() {
    mpu.getEvent(&a, &g, &temp);

    imu_accel_msg.point.x = a.acceleration.x;
    imu_accel_msg.point.y = a.acceleration.y;
    imu_accel_msg.point.z = a.acceleration.z;

    imu_gyro_msg.point.x = g.gyro.x;
    imu_gyro_msg.point.y = g.gyro.y;
    imu_gyro_msg.point.z = g.gyro.z;

    imu_accel_pub.publish(&imu_accel_msg);
    imu_gyro_pub.publish(&imu_gyro_msg);
}