
 * We do this in a while loop forever to ensure the device performs these tasks.
 * 
 * IMPORTANT: Using exit(); locks up the arduino in the current state.  This is 
 *            not desirable, so we avoid using it.
 */
void emergencyShutoff(){
  while(therapyMode == emergencyShutoffMode){
    Serial.println("Shuting off the motor");
    motorOff();
    delay(100);
    Serial.println("Opening finger and emergency valves.");
    deflateFinger();
    }
}
