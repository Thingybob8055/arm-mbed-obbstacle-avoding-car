//
// Created by Akshay on 28/01/2022.
// Code by Akshay Gopinath
// University of Essex
// PRID: GOPIN87305
//

#include "mbed.h"
#include "hcsr04.h"
#include "movement.h"

PwmOut steering(p21);
PwmOut velocity(p22);

HCSR04  usensor1(p25,p6);
HCSR04  usensor2(p24,p7);
HCSR04  usensor3(p23,p8);

int usensorDist1 = 0; //center
int usensorDist2 = 0; //right
int usensorDist3 = 0; //left
float vo=0;

void Velocity(float v) {
    v=v+1;
    if (v>=0 && v<=2) {
        if (vo>=1 && v<1) {                 //
            velocity.pulsewidth(0.0014);    // this is required to
            wait(0.1);                      //
            velocity.pulsewidth(0.0015);    // move into reverse
            wait(0.1);                      //
        }                                   //
        velocity.pulsewidth(v/2000+0.001);
        vo=v;
    }
}
// Steering expects -1 (left) to +1 (right)
void Steering(float s) {
    s=s+1;
    if (s>=0 && s<=2) {
        steering.pulsewidth(s/2000+0.001);
    }
}

int readSensor1() {
    usensor1.start();
    //wait_ms(500);
    usensorDist1=usensor1.get_dist_cm();
    return usensorDist1;
}

int readSensor2() {
    usensor2.start();
    //(500);
    usensorDist2=usensor2.get_dist_cm();
    return usensorDist2;
}

int readSensor3() {
    usensor3.start();
    //wait_ms(500);
    usensorDist3=usensor3.get_dist_cm();
    return usensorDist3;
}

void stop(){
    //pc.printf("[!]STOPPED");
    Steering(0);
    Velocity(0/100.0);
}

void moveForward(float vel){
    //pc.printf("[!]FORWARD");
    Steering(0);
    Velocity(vel/100.0);
}

void reverse(float vel){
    //pc.printf("[!]REVERSE");
    Steering(0);
    Velocity(-vel/100.0);
}

void turnLeft(float angle){
    //pc.printf("[!]LEFT");
    //Velocity(40/100);
    Steering(-angle);
}

void turnRight(float angle){
    //pc.printf("[!]RIGHT");
    //Velocity(40/100);
    Steering(angle);
}

void resetWheels() {
    Steering(0);
}

void resetSpeed() {
    Velocity(0/100.0);
}
