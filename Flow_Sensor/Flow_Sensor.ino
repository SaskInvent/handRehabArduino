#include <Wire.h>

//Experimental file for flow sensor codes
//If done and tested successfully, migrate to main files

//TWI pins location is predetermined by library
//SCL = A5;
//SDA = A4; 
const int address = 0x49; //default I2C address of flow sensor
int flowValue;
int fullScaleFlow;
int serialNo[4];
int count = -1;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); //join I2C bus as master
  delay(50); //allow flow sensor to perform warm up
  for (int i = 0; i<2; i++){
    Wire.requestFrom(address, 2);
    while (Wire.available()){
      serialNo[count++]= Wire.read();
    } 
    delay(15); //command response time
  } //First 2 read sequences return serial number
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(address,2);
  if (bitRead(Wire.read(),15)==0 && bitRead(Wire.read(),16)==0){
    flowValue = Wire.read();
  } //The first ﻿two bits of each flow reading will be 00, bitRead() reads from rightmost bit
}
