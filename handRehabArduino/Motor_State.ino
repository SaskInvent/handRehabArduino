
void motorOff(){
  digitalWrite(MOTOR_FORWARD, LOW);
  // all the valves are off. 
  // all the lights will be off
}

void motorOn(){
  digitalWrite(MOTOR_FORWARD, HIGH);
}
