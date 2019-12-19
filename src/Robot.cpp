#include "Arduino.h"
#include "Robot.h"
        
Robot::Robot(){
    //подключение к драйверу двигателей L298
    IN1 = 2; // Input1 подключен к выводу 2 
    IN2 = 7;
    ENA = 6;

    IN3 = 5; // Input3 подключен к выводу 5 
    IN4 = 4;
    ENB = 3;

    pinMode (ENA, OUTPUT); 
    pinMode (IN1, OUTPUT);
    pinMode (IN2, OUTPUT);

    pinMode (ENB, OUTPUT); 
    pinMode (IN3, OUTPUT);
    pinMode (IN4, OUTPUT);

     // На пару выводов "IN" поданы разноименные сигналы, мотор готов к вращению
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);

    // На пару выводов "IN" поданы разноименные сигналы, мотор готов к вращению
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);
}

void Robot::Forward(int lWheelSpeed, int rWheelSpeed){
  analogWrite(ENA,lWheelSpeed);
  analogWrite(ENB,rWheelSpeed);
}
void Robot::Backward(){

}
void Robot::Left(){

}
void Robot::Right(){

}

void Robot::Stop(){
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}