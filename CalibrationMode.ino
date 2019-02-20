



void calibrateFlexSensor(){
  motorOff();
  // Temporary calibration variables, allows restart and cancel of calibration.
  int tempFlexSensorHigh = INIT_FLEX_HIGH;
  int tempFlexSensorLow = INIT_FLEX_LOW;
  // TODO: Change the while loop statement, we will calibrate until the user says not to.
  // TODO: Review.  While loop statement may have to change to accomodate BlueTooth
  while (!Bluetooth.available()){ // TODO: Testing
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
  
  char BT_CalInput = 'Z';
  
  // TEMP/TESTING
  if(!Bluetooth.available()){
    Serial.println("Serial not available on exiting calibration");
    emergencyShutoff(); 
    return; // If we get back here do not continue execution.
  } else {
    BT_CalInput = Bluetooth.read();
    // TEMP/TESTING
    Serial.print("BT CAL INPUT RECIEVED: ");
    Serial.println(BT_CalInput);
  }

  // TODO: Compiler warns that BT_CalInput may not be initialized
  // If we recieve the char 'a', accept the new calibration.
  if(BT_CalInput == 'a'){
     flexSensorLow = tempFlexSensorLow;
     flexSensorHigh = tempFlexSensorHigh;
     therapyMode = 0;
     // Do not return here.  Continue on.
  } else if(BT_CalInput == 'r'){
    // If we recieve the char 'r', restart the calibration process.
    calibrateFlexSensor();
    return;
  } else if(BT_CalInput == 'c'){
    // If we recieve the char 'c', cancel the calibration process, and revert to the old cal.
    therapyMode = 0;
    return;
  } else {
    // Unexpected Bluetooth Serial input.  IF THIS EXECUTES IT IS A BUG!  
    Serial.println("UNEXPECTED BLUETOOTH SERIAL INPUT DURING CALIBRATION.  ABORTING.");
    emergencyShutoff();
    return;
  }
  
  if (flexSensorHigh - flexSensorLow < ACCEPTABLE_CALIBRATION_RANGE){
    flexSensorHigh = INIT_FLEX_HIGH;
    flexSensorLow = INIT_FLEX_LOW;
    // Could just continue calibration and print an error.
    Serial.println("Rejected calibration. \n\t REASON: Range to small.  Please retry.");
    emergencyShutoff();
    return;
  }else{
    motorOn(); //after sucessful calibration, start motor
    return;
  }
}




