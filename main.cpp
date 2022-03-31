//
// Created by Akshay on 28/01/2022.
// Code by Akshay Gopinath
// University of Essex
// PRID: GOPIN87305
//
 
#include "mbed.h"
#include "hcsr04.h"
#include "movement.h"
Serial pc(USBTX, USBRX); // tx, rx
const float vel = 30;
const float angle = 1;
 
int main(){
    Velocity(0);
    Steering(0);
    //moveForward();
    while(1) {
        int usensorDist1 = readSensor1();
        int usensorDist2 = readSensor2();
        int usensorDist3 = readSensor3();
        pc.printf("Distance 1 = %d\n\rDistance 2 = %d\n\rDistance 3 = %d\n\r", usensorDist1, usensorDist2, usensorDist3);
        if (usensorDist1 <= 20 || usensorDist2 <= 20 || usensorDist3 <= 20) {
            if(usensorDist1 <= 30 && usensorDist2 <= 30 && usensorDist3 <=30) {
                reverse(vel+10);
                turnRight(angle);
                pc.printf("[!]Reversing");
            }
            else if(usensorDist1 <= 30) {
                reverse(vel+10);
                turnRight(angle);
                pc.printf("[!]Reversing");
                
            }
            else if((usensorDist1 <= 20 && usensorDist2 <= 20) || usensorDist2 <= 20) {
                pc.printf("[!]Right");
                moveForward(vel);
                turnRight(angle);
                //wait_ms(500);
                //resetWheels();
                continue;
            }
            if((usensorDist1 <= 20 && usensorDist3 <= 20) || usensorDist3 <= 20) {
                moveForward(vel);
                pc.printf("[!]Left");
                turnLeft(angle);
                //wait_ms(500);
                //resetWheels();
                continue;
            }
            else {
                moveForward(vel);
                turnLeft(angle);
                //wait_ms(500);
                //resetWheels();
            }
        }
        else {
            moveForward(vel);
            pc.printf("[!]Forward\n\r");
            resetWheels();
        }
    }
}