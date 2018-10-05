
/*
 * Default therapy behaviour/mode.  Initializes the designated fingers to %50 of the calibrated
 * flex and maintains this state automatically unless there is an emergency, in which case
 * the emergency shutoff takes over.
 * 
 * Sequentially:
 *      - If safety thresholds are broken, shutdown.
 *      - If the maintenance threshold is broken, maintain pressure
 *      - If the deflation threshold is broken, lower the pressure and start over???
 *      - Otherwise: Inflate the finger.
 */
void activateDefaultMode(){
  bool deflating = false; // TEMP: Flag that sets the deflating state.
  bool inflating = false; // TEMP: Flag that sets the inflating state.
  
  if(trueFlex > SAFETY_THRESHOLD_HIGH || trueFlex < SAFETY_THRESHOLD_LOW){
    emergencyShutoff();
  }
  
  if(trueFlex > MAINTENANCE_THRESHOLD){
    inflating = false;
    if(trueFlex > DEFLATION_THRESHOLD){
      deflating = true;
    } else {
      deflating = false;
    }
  } 
  
  else {
    inflating = true;
  }

  if (deflating){
    // deflation takes priority over inflating, for safety reasons.
    deflateFinger();
  } else if (inflating){
    inflateFinger(PWM);
  } else {
    // If not inflating or deflating, then the pressure will be maintained.
    maintainFingerPressure();
  }
}