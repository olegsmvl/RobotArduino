#ifndef ODOMETER_H
#define ODOMETER_H

class Odometer
{
	public:
        Odometer();
        int GetOdometerR();
        int GetOdometerL();
        void Loop();
        void IncOdometerL();
        void IncOdometerR();
    private:
        int OdometerPinL;
        int OdometerPinR;
        int OdometerL;
        int OdometerR;
        bool PinStateL;
        bool PinStateR;
};
#endif