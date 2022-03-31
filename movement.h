//
// Created by Akshay on 28/01/2022.
// Code by Akshay Gopinath
// University of Essex
// PRID: GOPIN87305
//

#pragma once

void turnLeft(float angle);
void turnRight(float angle);
void moveForward(float vel);
void reverse(float vel);
void stop();
void resetSpeed();
void resetWheels();

//void readDistance();
int readSensor1();
int readSensor2();
int readSensor3();

void Velocity(float v);
void Steering(float s);