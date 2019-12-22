#include "Arduino.h"
#include "RobotManager.h"

RobotManager::RobotManager(){
    Robot robot;

    pinMode(8, OUTPUT); 
    digitalWrite(8, HIGH);
}

void RobotManager::ExecuteCommand(int command){
    switch(command){
      case lighton:
        digitalWrite(8, LOW);
        break;
      case lightoff:
        digitalWrite(8, HIGH);
        break;
      case forward:
        robot.Forward(100,100);
        break;
      case backward:
        robot.Backward(100,100);
        break;
      case left:
        robot.Left(100,100);
        break;
      case right:
        robot.Right(100,100);
        break;
      case stop:
        robot.Stop();
        break;
      default:
        break;
    }
}

void RobotManager::Loop(){
    robot.Loop();
}

int RobotManager::GetOdometerL(){
    return robot.odometer.GetOdometerL();
}

int RobotManager::GetOdometerR(){
    return robot.odometer.GetOdometerR();
}
