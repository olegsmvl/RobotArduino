/*
библиотека для дравера робота

схема подключения:

драйвер двигателей L298:
2- IN1
3- ENB
4- IN4
5- IN3
6- ENA
7- IN2
*/

#ifndef ROBOT_H
#define ROBOT_H

#include "Robot\Odometer.h"

class Robot
{
	public:
        Robot();
        void Forward(int lWheelSpeed, int rWheelSpeed);
        void Backward(int lWheelSpeed, int rWheelSpeed);
        void Left(int lWheelSpeed, int rWheelSpeed);
        void Right(int lWheelSpeed, int rWheelSpeed);
        void LeftValue(int lWheelSpeed, int rWheelSpeed, int value);
        void Stop();
        void Loop();
        Odometer odometer;
    private:
        int IN1;
        int IN2;
        int IN3;
        int IN4;
        int ENA;
        int ENB;
        int startValue;
        

};
#endif