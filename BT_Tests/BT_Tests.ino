// Source for tutorial: https://www.teachmemicro.com/arduino-bluetooth/
// NOTE: Would need a BLE module to work with iOS devices.
// Using Serial BLuetooth Terminal for testing on Android.
//

/*
 * HC-05 Bluetooth module
 *
 * ###########################################################################
 * ####################### AT-COMMAND mode. ##################################
 * ###########################################################################
 * 
 * AT commands are used to configure the HC-05 BT module.
 * 
 * NOTE: Since we use the RX and TX pins in this example, we will write directly to Serial.
 *       For other applications we will write to SoftwareSerial.
 * 
 * To enter AT-COMMAND mode:
 * 1. Upload an empty sketch to the Arduino. (Can not upload sketchs if ports 0 and 1 are in use)
 * 2. Unplug the Arduino from power and connect wires as follows:
 *      - Arduino GND to RESET  <=== Allows Arduino to become USB Serial adapter
 *      - Arduino RX to HC-05 RX
 *      - Arduino TX to HC-05 TX
 *      - Arduino 3.3V to HC-05 VCC
 *      - Arduino GND to HC-05 GND
 * 3. Hold the button on the HC-05 and plug the Arduino back in at the same time
 *      - Enters AT-COMMAND mode
 *      - If successful LED will blink 1 second on, 1 second off (on HC-05)
 * 4. Open the Arduino IDE Serial monitor (Ctrl-Shift-M)
 *      - Change the following settings in the Serial monitor:
 *        - baud rate to 38400
 *        - line endings to "Both NL & CR"
 *          - stands for newline and carriage return.  
 *          Without these characters Serial communication will fail.
 * 5. Send the following commands:
 *    - AT
 *    response: OK, if ERROR, try again
 *    - AT+UART
 *    response: AT+9600,0,0  (baud rate 9600, this is good)
 *    ################## Other commands to try ################
 *    - AT+PSWD
 *    - AT+ADDR
 *    - AT+ROLE
 *    - AT+VERSION
 *    - AT+STATE
 *    - AT+CMODE      // Connection mode
 *    
 *    ######################################################################
 *    ######################################################################
 *    ######################################################################
 *    
 *    
 */

// Uncomment empty script and upload if following AT-COMMAND example.
void setup(){
    
}

void loop(){
  
}
