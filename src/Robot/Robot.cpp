#include "Arduino.h"
#include "Robot.h"
        
Robot::Robot(){
    //подключение к драйверу двигателей L298
    
    ENA = 2;
    IN1 = 3;  
    IN2 = 4;

    IN3 = 5;  
    IN4 = 6;
    ENB = 7;

    pinMode (ENA, OUTPUT); 
    pinMode (IN1, OUTPUT);
    pinMode (IN2, OUTPUT);

    pinMode (ENB, OUTPUT); 
    pinMode (IN3, OUTPUT);
    pinMode (IN4, OUTPUT);
}

void Robot::Forward(int lWheelSpeed, int rWheelSpeed){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  
  analogWrite(ENA,lWheelSpeed);
  analogWrite(ENB,rWheelSpeed);
}
void Robot::Backward(int lWheelSpeed, int rWheelSpeed){
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  
  analogWrite(ENA,lWheelSpeed);
  analogWrite(ENB,rWheelSpeed);
}
void Robot::Left(int lWheelSpeed, int rWheelSpeed){
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  
  analogWrite(ENA,lWheelSpeed);
  analogWrite(ENB,rWheelSpeed);
}
void Robot::Right(int lWheelSpeed, int rWheelSpeed){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  
  analogWrite(ENA,lWheelSpeed);
  analogWrite(ENB,rWheelSpeed);
}

void Robot::Stop(){
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}

void Robot::Loop(){
  odometer.Loop();
}