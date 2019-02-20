// source: https://www.teachmemicro.com/arduino-bluetooth/#Control_a_LED_via_Bluetooth_and_Android
# include <SoftwareSerial.h>

/*
 * Use this sketch to test a BT module after AT mode has been confirmed to work.
 * TODO: We are supposed to be able to upload sketchs to the Arduino using BT.  I was unable to get this working.
 */

SoftwareSerial Bluetooth(12, 11); // RX, TX  (NOTE: RX is wired into HC-05 TXD,
                                  //                and TX is wired into HC-05 RXD)
                                  // RX = Recieve, TX = Transmission
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
