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

// struct defining the values to store for a user profile.
//struct UserProfile {
//  float prefMotorRate;
//  float indexFingerFlex;
//  float middleFingerFlex;
//  float ringFingerFlex;
//  float pinkyFingerFlex;
//  int preferedMode;
//} ;
// struct moved to main program.

// Oct 6th, 2018: REQUIRES TESTING.
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

// retrieve the previous user profile, if there is one.
// Return a reference to the user profile if one exists,
// null otherwise.
// Oct 6th, 2018: REQUIRES TESTING.
bool hasPreviousProfile(){
  // the CurrentUserProfile variable is defined in the main program.
  EEPROM.get(0, CurrentUserProfile);

  if(CurrentUserProfile.prefMotorRate != 0 && CurrentUserProfile.indexFingerFlex != 0){
    return true; 
  } else {
    // the intention is to calibrate and ask for user input if 
    // no previous profile is detected.
    return false;
  }
}

// Store the current user profile.
// Oct 6th, 2018: REQUIRES TESTING.
bool storeCurrentProfile(){
  UserProfile valuePassedIn = EEPROM.put(0, CurrentUserProfile);
  if(valuePassedIn.indexFingerFlex == CurrentUserProfile.indexFingerFlex){
    // We did indeed store the value.
    return true;
  } else {
    // We did not actually store the value...
    return false;
  }
}
