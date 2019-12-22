/*
библиотека для управления платформой робота 2WD для ардуино
*/
#include "Arduino.h"
#include "Robot_2wd.h"
#include "Servo.h"

Head::Head()
{
}

void Head::init()
{
  servo_turn.attach(22);
  servo_tilt.attach(23);
}

void Head::look_forward()
{
   servo_turn.write(90);
  servo_tilt.write(90);
}

void Head::look_left()
{
	servo_turn.write(30);
  servo_tilt.write(90);
}

void Head::look_right()
{
  servo_turn.write(180);
  servo_tilt.write(90);
}
