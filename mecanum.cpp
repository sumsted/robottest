#include "mecanum.h"


Mecanum::Mecanum(float width, float length, float minPwm, float maxPwm, float maxStick, float tune) :
    width(width), length(length), minPwm(minPwm), maxPwm(maxPwm), maxStick(maxStick), tune(tune){
}

void Mecanum::calculateWheelSpeed(float (&joystick)[3], int (&wheelSpeed)[4]){
    float speedRatio[4];
    float maxRatio = this->maxStick;
    byte i;

    speedRatio[0] = joystick[1] - joystick[0] + joystick[2] * ((this->width / 2)+(this->length /2));
    maxRatio = Mecanum::myabs(speedRatio[0]) > maxRatio ? Mecanum::myabs(speedRatio[0]) : maxRatio;
    speedRatio[1] = joystick[1] + joystick[0] - joystick[2] * ((this->width / 2)+(this->length /2));
    maxRatio = Mecanum::myabs(speedRatio[1]) > maxRatio ? Mecanum::myabs(speedRatio[1]) : maxRatio;
    speedRatio[2] = joystick[1] - joystick[0] - joystick[2] * ((this->width / 2)+(this->length /2));
    maxRatio = Mecanum::myabs(speedRatio[2]) > maxRatio ? Mecanum::myabs(speedRatio[2]) : maxRatio;
    speedRatio[3] = joystick[1] + joystick[0] + joystick[2] * ((this->width / 2)+(this->length /2));
    maxRatio = Mecanum::myabs(speedRatio[3]) > maxRatio ? Mecanum::myabs(speedRatio[3]) : maxRatio;

    for(i=0;i<4;i++){
        wheelSpeed[i] = (int) Mecanum::myround(((this->maxPwm - this->minPwm)/2.0*speedRatio[i])/maxRatio * this->tune + ((this->maxPwm + this->minPwm) / 2));
    }
}


float Mecanum::myround(float val){
    return float(val - int(val) >= 0.5 ? int(val)+1 : int(val));
}

float Mecanum::myabs(float val){
    return val < 0.0 ? -val : val;
}
