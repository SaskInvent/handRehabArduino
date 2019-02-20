
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
void testCalibrationOutput(int calFlexLow, int calFlexHigh){
  Serial.print("Flex value: ");
  Serial.print(flexValue);
  Serial.print("  Calibrating flex sensor:");
  Serial.print("min:");
  Serial.print(calFlexLow);
  Serial.print(" max:");
  Serial.println(calFlexHigh);
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
 * Print the results of reading input from BT.
 */
void loopReadingInput(){
  Serial.print("Changed Therapy Mode:");
  Serial.println(therapyMode);
}

/*
 * Prints main loop output to the console.
 */
void loopTestingOutput(){
  Serial.print("Flex: ");
  Serial.print(flexValue);
  Serial.print("  True flex: ");
  Serial.print(trueFlex);
  Serial.print("  PWM: ");
  Serial.println(PWM);
}
