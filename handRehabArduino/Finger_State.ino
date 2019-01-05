

/*
 * STATE: inflate the glove.  Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
 // void inflateFinger(int fingerID)
void inflateFinger(){
  Serial.print(" inflating finger now. Local PWM: ");
  Serial.print(PWM);
  Serial.print(" -> ");
  servoControl.write(angleControl); //Control the exhaust valve to determine the speed of finger inflation
  digitalWrite(fingerValve, LOW); //default state (at LOW) is open valve. 
  digitalWrite(emergencyValve, HIGH);
}

/*
 * STATE: inflate the glove.   Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
 // void deflateFinger(int fingerID)
void deflateFinger(){
  Serial.print(" deflating finger now ");
  servoControl.write(180); //Completely open exhaust valve to let the air out
  digitalWrite(fingerValve, LOW); //default state (at LOW) is open valve. 
  digitalWrite(emergencyValve, LOW);
}

/*
 * STATE: Maintian the pressure currently in the glove.   Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
 //void maintainFingerPressure(int fingerID)
void maintainFingerPressure(){
  Serial.print("MAINTIAN PRESSURE");
  digitalWrite(fingerValve, HIGH);
  digitalWrite(emergencyValve, HIGH);
}
