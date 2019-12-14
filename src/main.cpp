#include <Arduino.h>
#include <Wire.h> //I2C Arduino Library

#include <ArduinoJson.h>

  StaticJsonDocument<200> doc;
    int addr = 0x1E; //I2C Address for The HMC5883

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;



  Wire.begin();
Wire.beginTransmission(addr);
Wire.write(0x02);
Wire.write(0x00); //Continuously Measure
Wire.endTransmission();

  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
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

  serializeJson(doc, Serial);
  delay(50);
}
