

/*
 * STATE: inflate the glove.  Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
void inflateFinger(int localPWM){
  Serial.print(" inflating finger now. Local PWM: " + String(localPWM) + " -> ");
}

/*
 * STATE: inflate the glove.   Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
void deflateFinger(){
  Serial.print(" deflating finger now ");
}

/*
 * STATE: Maintian the pressure currently in the glove.   Interfaces with either the motor AND pump,  
 * OR with the ??? flow control ??? valves as neccessary.
 */
void maintainFingerPressure(){
  Serial.print(" MAINTIAN PRESSURE ");
}
