
/**
 * This file allows us to abstract away the actual details of writing
 * to the individual valves.
 */
void openFingerValve(int fingerID){
  digitalWrite(fingerID, LOW); //default state (at LOW) is open valve. 
}

void closeFingerValve(int fingerID){
  digitalWrite(fingerID, HIGH); //default state (at LOW) is open valve. 
}

void openEmergencyValve(){
  digitalWrite(emergencyValve, LOW);
}

void closeEmergencyValve(){
  digitalWrite(emergencyValve, HIGH);
}

void openAllValves(){
  for(int i=0; i<SIZE_OF; i++){
    openFingerValve(fingerValves[i]);  
  }
  openEmergencyValve();
}
