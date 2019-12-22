#ifndef ROBOTMANAGER_H
#define ROBOTMANAGER_H

#include "Commands.h"
#include "Robot\Robot.h"

class RobotManager
{
	public:
        RobotManager();
        void ExecuteCommand(int command);
        void Loop();
        int GetOdometerL();
        int GetOdometerR();
        Robot robot;
    private:
          
          

};
#endif