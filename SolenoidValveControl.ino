
/**
 * This file allows us to abstract away the actual details of writing
 * to the individual valves.
 */
void openFingerValve(){
  digitalWrite(fingerValve1, LOW); //default state (at LOW) is open valve. 
}

void closeFingerValve(){
  digitalWrite(fingerValve1, HIGH); //default state (at LOW) is open valve. 
}

void openEmergencyValve(){
  digitalWrite(emergencyValve, LOW);
}

void closeEmergencyValve(){
  digitalWrite(emergencyValve, HIGH);
}

void openAllValves(){
  openFingerValve();
  openEmergencyValve();
}
