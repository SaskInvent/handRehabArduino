
void calibrateFlexSensor(){
  motorOff();
  // Temporary calibration variables, allows restart and cancel of calibration.
  int tempFlexSensorHigh = INIT_FLEX_HIGH;
  int tempFlexSensorLow = INIT_FLEX_LOW;
  // TODO: Change the while loop statement, we will calibrate until the user says not to.
  // TODO: Review.  While loop statement may have to change to accomodate BlueTooth
  while (!Serial.available()){
    flexValue=analogRead(flexInput);
    // OUTPUT: Testing calibration.
    testCalibrationOutput(tempFlexSensorLow, tempFlexSensorHigh);
    
    if (flexValue>tempFlexSensorHigh) {
      tempFlexSensorHigh = flexValue;
    }
    if (flexValue<tempFlexSensorLow) {  
      if (flexValue>100){
        tempFlexSensorLow = flexValue;
      }
    }
    delay(100);
  }
  
  char rpiCalInput = 'Z';
  
  // TEMP/TESTING
  if(!Serial.available()){
    Serial.println("Serial not available on exiting calibration");
    emergencyShutoff(); 
  } else {
    rpiCalInput = Serial.read();
    // TEMP/TESTING
    Serial.print("RPI CAL INPUT RECIEVED: ");
    Serial.println(rpiCalInput);
  }

  // TODO: Compiler warns that rpiCalInput may not be initialized
  // If we recieve the char 'a', accept the new calibration.
  if(rpiCalInput == 'a'){
     flexSensorLow = tempFlexSensorLow;
     flexSensorHigh = tempFlexSensorHigh;
     therapyMode = 0;
     return;
  } else if(rpiCalInput == 'r'){
    // If we recieve the char 'r', restart the calibration process.
    calibrateFlexSensor();
  } else if(rpiCalInput == 'c'){
    // If we recieve the char 'c', cancel the calibration process, and revert to the old cal.
    therapyMode = 0;
    return;
  } else {
    // Unexpected Serial input.  IF THIS EXECUTES IT IS A BUG!  
    Serial.println("UNEXPECTED SERIAL INPUT DURING CALIBRATION.  ABORTING.");
    emergencyShutoff();
  }
  
  if (flexSensorHigh - flexSensorLow < ACCEPTABLE_CALIBRATION_RANGE){
    flexSensorHigh = INIT_FLEX_HIGH;
    flexSensorLow = INIT_FLEX_LOW;
    // Could just continue calibration and print an error.
    Serial.println("Rejected calibration. \n\t REASON: Range to small.  Please retry.");
    emergencyShutoff();
  }else{
    motorOn(); //after sucessful calibration, start motor
  }
}