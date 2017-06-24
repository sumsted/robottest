#ifndef MECANUM_H
#define MECANUM_H

#include <Arduino.h>

class Mecanum {
    public:
        Mecanum(float width, float height, float minPwm, float maxPwm, float maxStick, float tune);
        void calculateWheelSpeed(float (&joystick)[3], int (&wheelSpeed)[4]);
        static float myabs(float val);
        static float myround(float val);
    private:
        float width;
        float length;
        float minPwm;
        float maxPwm;
        float tune;
        float maxStick;
};

#endif