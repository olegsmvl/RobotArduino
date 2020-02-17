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
        void IncOdometerL();
        void IncOdometerR();
        Robot robot;
    private:
          
          

};
#endif