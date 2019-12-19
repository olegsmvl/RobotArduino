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

class Robot
{
	public:
        Robot();
        void Forward(int lWheelSpeed, int rWheelSpeed);
        void Backward();
        void Left();
        void Right();
        void Stop();
    private:
        int IN1;
        int IN2;
        int IN3;
        int IN4;
        int ENA;
        int ENB;

};
#endif