

/*
 * STATE: inflate the glove.  Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
void inflateFinger(int fingerID){
  Bluetooth.print(" inflating fingers now: ");
  Bluetooth.print(" -> ");
  motorOn();
  servoControl.write(angleControl); //Control the exhaust valve to determine the speed of finger inflation
  openFingerValve(fingerID);
//  closeEmergencyValve();
}

/*
 * STATE: inflate the glove.   Interfaces with either the motor AND pump,
 * OR with the ??? flow control ??? valves as neccessary.
 */
void deflateAllFingers(){
  Bluetooth.print(" deflating fingers. ");
  motorOff();
  servoControl.write(180); //Completely open exhaust valve to let the air out
  openAllValves();
}

/*
 * STATE: Maintian the pressure currently in the glove.   Interfaces with either the motor AND pump,
 * OR with the ??? flow control ??? valves as neccessary.
 */
void maintainFingerPressure(int fingerID){
  Bluetooth.print("MAINTIAN PRESSURE ");
  closeFingerValve(fingerID);
//  closeEmergencyValve();
}
