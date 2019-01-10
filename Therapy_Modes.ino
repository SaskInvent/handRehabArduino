
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
  bool deflating = false; // TEMP: Flag that sets the deflating state.
  bool inflating = false; // TEMP: Flag that sets the inflating state.

  motorOn();
  
  if(trueFlex > SAFETY_THRESHOLD_HIGH || trueFlex < SAFETY_THRESHOLD_LOW){
    emergencyShutoff();
  }

  // TODO: Review and test with team.
  // This logic needs to be clarified and varified
  // before proceeding to more complex behaviour.
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
    deflateFinger();
  } else if (inflating){
    inflateFinger();
  } else {
    // If not inflating or deflating, then the pressure will be maintained.
    maintainFingerPressure();
  }
}


/**
 * Mode to: 
 *   - shut off the motor
 *   - open the valves
 *   - and wait.
 */
void activateIdleMode(){
  motorOff();
  
  // TODO: Open solenoid valves
  
}
