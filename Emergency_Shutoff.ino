
/*
 * The safest thing to do is shutoff the motor and pump, then open the valves.
 * We do this in a while loop forever to ensure the device is shutoff whenever
 * the button is pressed.
 *
 * NOTE: RESETS and returns to 
 */
void emergencyShutoff(){
  while(true){
    if(Bluetooth.available()){
      char tempEmergencyInput = Bluetooth.read();
      if(tempEmergencyInput=='R'){
        therapyMode = idleMode;
        return;
      }
      // Else: Continue, since we only reset if we recieve an 'R'
    }
    Serial.print("Shuting off the motor");
    motorOff();
    delay(100);
    Serial.println("Opening finger and emergency valves.");
    deflateFinger();
  }
}
