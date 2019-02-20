# include <SoftwareSerial.h>

SoftwareSerial Bluetooth(11, 10); // RX, TX
int LED = 13; // The on-board LED
int Data; // Data recieved

void setup(){
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Send 1 to turn on the LED.  Send 0 to turn OFF");
  pinMode(LED, OUTPUT);
}

void loop(){
  if(Bluetooth.available()){ // Wait for data recieved
    Data=Bluetooth.read();
    if(Data=='1'){
      digitalWrite(LED,1);
      Serial.println("LED On!");
      Bluetooth.println("LED On!!");
    }
    else if(Data=='0'){
      digitalWrite(LED,0);
      Serial.println("LED Off!");
      Bluetooth.println("LED On D13 Off ! ");
    }
    else{;} // noop
  }
  delay(100);
}
