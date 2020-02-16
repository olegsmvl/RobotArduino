#include <Arduino.h>
#include <Wire.h> //I2C Arduino Library
//#include <Robot\Robot_2wd.h>
#include "RobotManager.h"
#include "Robot\Encoder.h"

#include <ArduinoJson.h>

  StaticJsonDocument<200> doc;
  StaticJsonDocument<200> InData;
  int addr = 0x1E; //I2C Address for The HMC5883
  String inString;

  RobotManager robotManager;
  Encoder encoder;
  bool on;  //светоодиод по таймеру

  int EncoderLpin = 18;
  int EncoderRpin = 19;

  int EncoderLcount = 0;
  int EncoderRcount = 0;

void EncoderL(){
  EncoderLcount++;
}

void EncoderR(){
  EncoderRcount++;
}

void InterruptInit(){
  sei();
  pinMode(EncoderLpin, INPUT_PULLUP);
  pinMode(EncoderRpin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(EncoderLpin), EncoderL, CHANGE);
  attachInterrupt(digitalPinToInterrupt(EncoderRpin), EncoderR, CHANGE);
}


void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  Wire.begin();
  Wire.beginTransmission(addr);
  Wire.write(0x02);
  Wire.write(0x00); //Continuously Measure
  Wire.endTransmission();
  InterruptInit();

  on = false;
  sei();
  encoder.Init();
  
  pinMode(12, OUTPUT);

  // Allocate the JSON document
  //
    
  // Don't forget to change this value to match your requirement.
  // Use arduinojson.org/v6/assistant to compute the capacity.


  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument  doc(200);

  // Add values in the document
  //



}

void loop() {
  robotManager.Loop();
  
  int x,y,z; //triple axis data
  Wire.beginTransmission(addr);
  Wire.write(0x03);
  Wire.endTransmission();
  //Read the data
  Wire.requestFrom(addr, 6);
  if(6<=Wire.available())
    {
      x = Wire.read()<<8; //MSB  x 
      x |= Wire.read(); //LSB  x
      z = Wire.read()<<8; //MSB  z
      z |= Wire.read(); //LSB z
      y = Wire.read()<<8; //MSB y
      y |= Wire.read(); //LSB y
    }

  doc["x"] = x;
  doc["y"] = y;
  doc["z"] = z;
  //doc["ol"] = robotManager.GetOdometerL();
  //doc["or"] = robotManager.GetOdometerR();
  doc["ol"] = EncoderLcount;
  doc["or"] = EncoderRcount;

  serializeJson(doc, Serial);

while (Serial.available() > 0) {
  int inChar = Serial.read();
    inString += (char)inChar; 
  if (inChar == '}') {
    Serial.print("String: ");
    Serial.println(inString);

    deserializeJson(InData, inString);
    int command = InData["command"];
    Serial.print("command: ");
    Serial.println(command);

    robotManager.ExecuteCommand(command);

    inString = ""; 
  }
}


  //delay(100);
}

ISR(TIMER4_COMPA_vect){   //обработчик прерывания от таймера
  on = !on;
  if (on)
    digitalWrite(12, HIGH);
  else
     digitalWrite(12, LOW);
}
