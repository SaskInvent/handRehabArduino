// If the arduinos we are using have persistent EEPROM, these functions will 
// allow us to manipulate it.
//  EEPROM is read or written one byte at a time.  Values between 0-255
//  can be stored.  
//  
//  NOTE:  EEPROM has a specified life of 100,000 read/write cycles.
//  
//  NOTE:  We may want to initialize a variable that recorde the address of the next avaialble byte.
//  We also need to keep the address of any stored values/structs.  In practice should only need to 
//  store one at a time (one for the current patient)

#include <EEPROM.h>

void clearEEPROM(){
  // initializes each value in EEPROM to 0, preparing it for
  // writing in the future.  Not sure why this would be necessary
  // but it is in the official docs.
  for(int i = 0; i < EEPROM.length(); i++){
    // EEPROM.update is prefered to EEPROM.write, since it only writes if the values differ.
    EEPROM.update(i, 0);
    if(i == EEPROM.length()){
      Serial.print("There are ");
      Serial.print(i);
      Serial.print(" memory addresses in EEPROM");
    }
  }
  // NOTE: Addresses in memory that have never been written to will hold a value of 255
}


struct UserProfile{
  int preferedMode;
  float prefMotorRate;
  float indexFingerFlex;
  float middleFingerFlex;
  float ringFingerFlex;
  float pinkyFingerFlex;
}
