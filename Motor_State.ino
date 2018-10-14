
void motorOff(){
  digitalWrite(MOTOR_FORWARD, LOW);
  // all the valves is off. 
  // all the lights will be off
}

void motorOn(){
  digitalWrite(MOTOR_FORWARD, HIGH);
}
