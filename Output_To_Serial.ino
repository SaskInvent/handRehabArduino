
/*
 * Print the results of setup to the console.
 */
void testingSetupOutput(){
  Bluetooth.print("Integer value of A1:  ");
  Bluetooth.println(flexInput);
}

/*
 * Print calibration output to the console.
 */
void testCalibrationOutput(int calFlexLow, int calFlexHigh){
  Bluetooth.print("Flex value: ");
  Bluetooth.print(flexValue);
  Bluetooth.print("  Calibrating flex sensor:");
  Bluetooth.print("min:");
  Bluetooth.print(calFlexLow);
  Bluetooth.print(" max:");
  Bluetooth.println(calFlexHigh);
}


/*
 * Prints the final calibrated values to Bluetooth output.
 */
void testingFinalCalibrationOutput(){
  //Printing the most important values to the Bluetooth monitor
  Bluetooth.print("Max Value of Flex Sensor: ");
  Bluetooth.print(flexSensorHigh);
  Bluetooth.print("Min Value of Flex Sensor: ");
  Bluetooth.println(flexSensorLow);
  delay(3000);
}

/*
 * Print the results of reading input from BT.
 */
void loopReadingInput(){
  Bluetooth.print("Changed Therapy Mode: ");
  Bluetooth.println(therapyMode);
}

/*
 * Prints main loop output to the console.
 */
void loopTestingOutput(){
  Bluetooth.print("Flex: ");
  Bluetooth.print(flexValue);
  Bluetooth.print("  True flex: ");
  Bluetooth.println(trueFlex);
}
