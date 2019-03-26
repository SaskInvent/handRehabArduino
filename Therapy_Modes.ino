
/*
 * Inflation therapy behaviour/mode.  Initializes the designated fingers to %50 of the calibrated
 * flex and maintains this state automatically unless there is an emergency, in which case
 * the emergency shutoff takes over.
 * 
 * Sequentially:
 *      - If safety thresholds are broken, shutdown.
 *      - If the maintenance threshold is broken, maintain pressure
 *      - If the deflation threshold is broken, lower the pressure and start over???
 *      - Otherwise: Inflate the finger.
 */
void activateInflateMode(){

  // TEMP/TESTING
  Bluetooth.print("activateInflateMode ");
  bool deflating = false; // TEMP: Flag that sets the deflating state.
  bool inflating = false; // TEMP: Flag that sets the inflating state.

  if(trueFlex > SAFETY_THRESHOLD_HIGH || trueFlex < SAFETY_THRESHOLD_LOW){
    emergencyShutoff("trueFlex outside of threshold: trueFlex -> " + trueFlex);
    return;
  }

  if(trueFlex > MAINTENANCE_THRESHOLD-TOLERANCE){
    inflating = false;
    if(trueFlex > MAINTENANCE_THRESHOLD+TOLERANCE){
      deflating = true;
    } else {
      deflating = false;
    }
  } else {
    inflating = true;
  }

  if (deflating){
    // deflation takes priority over inflating, for safety reasons.
    motorOff();
    deflateAllFingers();
  } else if (inflating){
    motorOn(); // TEMP/PRESENTATION: This is here for lack of a better place.
    closeEmergencyValve();
    for(int i=0; i<SIZE_OF; i++){ // TEMP/PRESENTATION
      inflateFinger(fingerValves[i]);
    }
  } else {
    motorOff();
    closeEmergencyValve();
    // If not inflating or deflating, then the pressure will be maintained.
    for(int i=0; i<SIZE_OF; i++){ // TEMP/PRESENTATION
      maintainFingerPressure(fingerValves[i]);
    }
  }
}


/**
 * Mode to: 
 *   - shut off the motor
 *   - open the valves
 *   - and wait.
 */
void activateIdleMode(){
  Bluetooth.print("activateIdleMode ");
  motorOff();
  openAllValves();
}
