#include "Arduino.h"
#include "Odometer.h"
        
Odometer::Odometer(){
   
    OdometerPinL = 8;
    OdometerPinR = 10;  

    pinMode (OdometerPinL, INPUT_PULLUP); 
    pinMode (OdometerPinR, INPUT_PULLUP); 

    OdometerL = 0;
    OdometerR = 0;
}

int Odometer::GetOdometerL(){
  return OdometerL;
}

int Odometer::GetOdometerR(){
  return OdometerR;
}

void Odometer::Loop(){
    bool currentPinStateL;
    bool currentPinStateR;
    
    if (digitalRead(OdometerPinL) == LOW){
        currentPinStateL = true;
    }
    else{
        currentPinStateL = false;
    }

    if (digitalRead(OdometerPinR) == LOW){
        currentPinStateR = true;
    }
    else{
        currentPinStateR = false;
    }

    if (currentPinStateL != PinStateL){
        if (currentPinStateL == true){
            OdometerL++;
            PinStateL =currentPinStateL;
        }
    }

    if (currentPinStateR != PinStateR){
        if (currentPinStateR == true){
            OdometerR++;
            PinStateR =currentPinStateR;
        }
    }
}