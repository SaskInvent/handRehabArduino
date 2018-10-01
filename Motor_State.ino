

const int m_state_off= 3 ;// red
const int m_state_on = 4; // white
const int m_state_emergency = 5; // blue


void motorStateSetup() {
  // put your setup code here, to run once

  pinMode(m_state_on, OUTPUT );
  pinMode(m_state_off, OUTPUT );
  pinMode(m_state_emergency, OUTPUT );

  digitalWrite(m_state_off, LOW );
  digitalWrite(m_state_on, LOW );
  digitalWrite(m_state_emergency, LOW );
}

void motorTestingLoop() {
  int control = 69; // this will control the lights

  switch(control){
    case 0: 
    digitalWrite(m_state_off, HIGH);
    break;
    case 1: 
    digitalWrite(m_state_on, HIGH);
    break;
    case 5:  
    digitalWrite(m_state_emergency, HIGH);
    break;
  }
}

void off_state(){
  // all the valves is off. 
  // all the lights will be off
}

void emergency_state(){
  off_state();
}

void on_state(){
  
}
