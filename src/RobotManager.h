#ifndef ROBOTMANAGER_H
#define ROBOTMANAGER_H

#include "Commands.h"
#include "Robot\Robot.h"

class RobotManager
{
	public:
        RobotManager();
        void ExecuteCommand(int command);
    private:
          Robot robot;

};
#endif