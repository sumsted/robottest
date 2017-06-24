#ifndef SWERVE_H
#define SWERVE_H

#include <math.h>

struct WheelVector {
    float angle;
    float speed;
};

class Swerve{
    public:
        Swerve(float width, float length, float maxSpeed, float maxStick, float tune);
        void calculateWheelVector(float (&joystick)[3], WheelVector (&vectors)[4]);
    private:
        float width;
        float length;
        float maxSpeed;
        float tune;
        float maxStick;
};
#endif