

/*
 * STATE: inflate the glove.  Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
 // void inflateFinger(int fingerID)
void inflateFinger(){
  Serial.print(" inflating finger now. Local PWM: ");
  Serial.print(PWM);
  Serial.print(" -> ");
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
  Serial.print(" deflating finger now ");
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
  Serial.print("MAINTIAN PRESSURE");
  motorOff();
  closeFingerValve();
  closeEmergencyValve();
}
