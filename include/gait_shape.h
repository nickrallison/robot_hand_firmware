#ifndef GAIT_SHAPE_H
#define GAIT_SHAPE_H

typedef struct footPoint{
    double x;
    double y;
    double z;
    bool ground;
} footPoint;


typedef struct gaitShape{
    footPoint frontRight;
    footPoint frontLeft;
    footPoint rearRight;
    footPoint rearLeft;
} gaitShape;

#endif //GAIT_SHAPE_H