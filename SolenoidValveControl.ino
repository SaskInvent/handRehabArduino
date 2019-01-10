

void openFingerValve(){
  digitalWrite(fingerValve, LOW); //default state (at LOW) is open valve. 
}

void closeFingerValve(){
  digitalWrite(fingerValve, HIGH); //default state (at LOW) is open valve. 
}

void closeEmergencyVvalve(){
  digitalWrite(emergencyValve, HIGH);
}

void openEmergencyValve(){
  digitalWrite(emergencyValve, LOW);
}

void openAllValves(){
  digitalWrite(emergencyValve, LOW);
  digitalWrite(fingerValve, LOW);
}
