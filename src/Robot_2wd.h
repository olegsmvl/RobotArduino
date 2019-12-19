/*
библиотека для управления платформой робота 2WD для ардуино
*/
#ifndef Robot_2wd_h
#define Robot_2wd_h

#include <Servo.h>

class Head
{
	public:
	Head();
	void look_forward();
	void look_left();
	void look_right();
	void init();
	private:
	Servo servo_turn;	// создание объекта - серва поворота головы
	Servo servo_tilt;	// создание объекта - серва наклона головы
};
#endif
 