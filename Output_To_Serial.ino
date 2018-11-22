
/*
 * Print the results of setup to the console.
 */
void testingSetupOutput(){
  Serial.print("Integer value of A1:  ");
  Serial.println(flexInput);
}

/*
 * Print calibration output to the console.
 */
void testCalibrationOutput(){
  Serial.print("Flex value: ");
  Serial.print(flexValue);
  Serial.print("  Calibrating flex sensor:");
  Serial.print("min:");
  Serial.print(flexSensorLow);
  Serial.print(" max:");
  Serial.println(flexSensorHigh);
}


/*
 * Prints the final calibrated values to Serial output.
 */
void testingFinalCalibrationOutput(){
  //Printing the most important values to the serial monitor
  Serial.print("Max Value of Flex Sensor: ");
  Serial.print(flexSensorHigh);
  Serial.print("Min Value of Flex Sensor: ");
  Serial.println(flexSensorLow);
  delay(3000);
}

/*
 * Prints main loop output to the console.
 */
void loopTestingOutput(){
  Serial.print("Flex: ");
  Serial.print(flexValue);  
  Serial.print("  True flex: ");
  Serial.print(trueFlex); // this value is divided by 10 because the lcd changes place values if not 
                              // (ask nelson or brendon)
  Serial.print("  PWM: ");
  Serial.println(PWM);
}
