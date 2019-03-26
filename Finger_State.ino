

/*
 * STATE: inflate the glove.  Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
 // void inflateFinger(int fingerID)
void inflateFinger(){
  Bluetooth.print(" inflating finger now: ");
  Bluetooth.print(" -> ");
  motorOn();
  servoControl.write(angleControl); //Control the exhaust valve to determine the speed of finger inflation
  openFingerValve();
  closeEmergencyValve();
}

/*
 * STATE: inflate the glove.   Interfaces with either the motor AND pump,
 * OR with the ??? flow control ??? valves as neccessary.
 */
 // void deflateFinger(int fingerID)
void deflateFinger(){
  Bluetooth.print(" deflating finger now ");
  motorOff();
  servoControl.write(180); //Completely open exhaust valve to let the air out
  openAllValves();
}

/*
 * STATE: Maintian the pressure currently in the glove.   Interfaces with either the motor AND pump,
 * OR with the ??? flow control ??? valves as neccessary.
 */
 //void maintainFingerPressure(int fingerID)
void maintainFingerPressure(){
  Bluetooth.print("MAINTIAN PRESSURE");
  motorOff();
  closeFingerValve();
  closeEmergencyValve();
}
