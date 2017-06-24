#include <Arduino.h>
#include "mecanum.h"
#include "swerve.h"

// Mecanum m(40.0, 60.0, 499, 2500, 1.0, 0.5);
Swerve s(40.0, 60.0, 100.0, 1.0, .5);
Mecanum m(40.0, 60.0, 499, 2500, 1.0, 0.5);

void testSwerve(float x, float y, float w){
    WheelVector v[4];
    float joystick[3] = {x, y, w};
    s.calculateWheelVector(joystick, v);
    int i;
    for(i=0;i<4;i++){
        Serial.print("w["+String(i)+"] = ("+String(v[i].angle)+", "+String(v[i].speed)+")\n");
    }
}

void testMecanum(float x, float y, float w){
    int wheelSpeed[4];
    float joystick[3] = {x, y, w};
    m.calculateWheelSpeed(joystick, wheelSpeed);
    int i;
    for(i=0;i<4;i++){
        Serial.print("w["+String(i)+"] = "+String(wheelSpeed[i])+"\n");
    }
}

void setup() {
    // put your setup code here, to run once:
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    Serial.println("robottest");

    Serial.println("Testing Swerve");
    testSwerve(1.0, 1.0, 0.0);

    Serial.println("Testing Mecanum");
    testMecanum(.25,.75,.3);
}

void blink(){
    // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(50); 
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50); 

    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(100); 
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100); 
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(100); 
}
void loop() {

    float x, y, w;
    for(x = -1.0; x <= 1.0;x += .1){
        for(y = -1.0; y <= 1.0; y += .1){
            for(w = -1.0; w <= 1.0; w += .1){
                Serial.println("Testing Swerve: "+String(x)+", "+String(y)+", "+String(w));
                testSwerve(x, y, w);

                // Serial.println("Testing Mecanum: "+String(x)+", "+String(y)+", "+String(w));
                // testMecanum(x, y, w);
                blink();
            }                
        }
    }
    
}
