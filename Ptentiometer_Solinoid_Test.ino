
////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// BEGIN INITIALIZING GLOBALS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

// Constants for the Flex Sensor and Potentiometer Readings. 
// This is detailing, the pin numbers that are used for input or output 
const int potInput = A0; // Analog input 2, potentiometer input.
const int flexInput = A1; // Analog input 1, for flex sensor input.
const int emergencyValve = 5; // Release valve
const int fingerValve =  7;  // Regular finger valve
const int button = 8; // Emergency release button.
const int MOTOR_FORWARD = 9; // forward motor control

// constants for automated flex sensor threshold logic and automated emergency shutoff.
const int SAFETY_THRESHOLD_HIGH = 1000;     // All values compared to input from trueFlex.
const int SAFETY_THRESHOLD_LOW = -100;
const int MAINTENANCE_THRESHOLD = 500; // Used in the main "void loop()" function.
const int DEFLATION_THRESHOLD = 650;   //

// These constants are used for calibrating the flex sensor at the start of the trials. 
// These will be eventually replaced when we can
// hold a consistant calibration between trails (aka signal conditioning).
int flexSensorLow = 1023; // INITIALIZATION: This number will be the lower of the 2 after 
                          // the calibration loop.
int flexSensorHigh = 0; // INITIALIZATION: Will be the HIGHER number after the calibration loop.

int flexValue; // The value read from the flex sensor.
int trueFlex; // Will be the remapped value read from the flex sensor.
int potValue; // The potentiometer value read.
int buttonTest; // Reads 

int PWM = 0; // Controls motor driver. Value betweem 0-255. GETS MAPPED FROM MAP 0-1023!

////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// END INITIALIZING GLOBALS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// BEGIN SETUP FUNCTIONS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*
 * Initialize all output/input pins.
 */
void initializePins(){
  pinMode(fingerValve, OUTPUT);
  pinMode(emergencyValve, OUTPUT);

  pinMode(MOTOR_FORWARD, OUTPUT); // Takes variable integer values to set the speed of the motor.

  pinMode(button, INPUT); // Used to stop the motor, and release the pressure in the system.

}

////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END SETUP FUNCTIONS ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// BEGIN SETUP /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*
 * Initialize the setup. 
 * 
 * Runs automatically at the beginning of any program.  Use to initialize all
 * input and output pins.  
 */
void setup() {
  // put your setup code here, to run once:
  
  // These commands are for the serial monitor, which can be found under tools tab up top.
  // This is useful for reporting of the potentiometer value as well as the resistance value 
  // of the flex sensor (mapped between 0 and 1023)  
  Serial.begin(9600);

  // Setting the Pinmodes of the arduino, these may be changed later base on the 
  // board that we end up using in future versions 
  initializePins();

  
  digitalWrite(fingerValve, LOW);
  digitalWrite(emergencyValve, LOW);

  potValue=analogRead(potInput); // 

  // OUTPUT: Tests the initialization of the pins.
  testingSetupOutput();
  
  // This is the command for the calibration in the first 10 seconds. 
  // This code will be REPLACED by a START button when we can signal 
  // condition and hold the calibration of the flex sensor between trials. 
  /*
   * Calibrates the flex sensor.  
   * Normal series of actions.
   * REWORK: Let the user define when calibration is done.
   */
  while (millis() <10000){
    flexValue=analogRead(flexInput);
    // OUTPUT: Testing calibration.
    testCalibrationOutput();
    
    if (flexValue>flexSensorHigh) {
      flexSensorHigh = flexValue;
    }
    if (flexValue<flexSensorLow) {
      if (flexValue>100){
        flexSensorLow = flexValue;
      }
    }
    delay(100);
  }
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// END SETUP ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// BEGIN LOOP FUNCTIONS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// END LOOP FUNCTIONS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// BEGIN MAIN LOOP /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  /////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////// BEGIN EMERGENCY SHUTOFF ////////////////////////////////////////////
  // Returns 0 or 1.                                                                        ///
  // 0 means 0V, 1 for 5V                                                                   ///
  // 0V == LOW, 5V == HIGH                                                                  ///
  //////////////// TEMP: An electrical solution will be hardwired in the future. //////////////
  buttonTest = digitalRead(button);
  if(buttonTest == HIGH){
    emergencyShutoff();
  }
  //////////////////////// END EMERGENCY SHUTOFF ///////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////// BEGIN READING SYSTEM INPUT //////////////////////////////////////////
  // Reading of the flex sensor value that is attached to the finger balloon
  // The map function is used to increase our resolution from whatever the 
  // calibrated range is to the maximum possible range (0-1023, based on 8 bit 
  // resolution of arduino uno)
  flexValue=analogRead(flexInput);

  // The flex value remapped to take advantage of our full range of possible values.  
  // NOTE: This can be less than 0 or higher than 1023 in some cases.  This is due to 
  // the remapping and can be used to establish upper and lower bounds on flex if desired.
  trueFlex=map(flexValue, flexSensorLow, flexSensorHigh, 0, 1023);

  // Workaround, analogue synthesizer.  Simulate voltages between 0V and 5V
  // Control the motor speed.  
  PWM = map(analogRead(potInput), 0, 1023, 0, 255); // Maps the value of potentiometer to PWM ranges

  /////////////////////////////// END READING SYSTEM INPUT /////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // OUTPUT: Prints the flex values ect to Serial output. //////////////////////////////////////////
  loopTestingOutput();                                                                  ////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////
  
  // Turning the light on when the the value of the mapped flex sensor matches within +/- 50 of the 
  // potentiometer value. The delay is set so the arduino checks every 300 ms and reports the value 
  // to the serial monitor. All values here are subject to change based on requirements of system. 

  // Ensures the emergency valve is closed.
  // REWORK: Make this part of a state.  Every state should control the exact configuration of the 
  // motor, pump, and valves as required.  This adheres to the principle of least surprise.
  // digitalWrite(emergencyValve, HIGH);

  bool deflating = false; // TEMP: Flag that sets the deflating state.
  bool inflating = false; // TEMP: Flag that sets the inflating state.

  ///////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////// BEGIN STATECHANGE LOGIC /////////////////////////////////////////
  /*
   * Sequentially:
   *      - If safety thresholds are broken, shutdown.
   *      - If the maintenance threshold is broken, maintain pressure
   *      - If the deflation threshold is broken, lower the pressure and start over???
   *      - Otherwise: Inflate the finger.
   */
  if(trueFlex > SAFETY_THRESHOLD_HIGH || trueFlex < SAFETY_THRESHOLD_LOW){
    emergencyShutoff();
  }
  
  if(trueFlex > MAINTENANCE_THRESHOLD){
    inflating = false;
    if(trueFlex > DEFLATION_THRESHOLD){
      deflating = true;
    } else {
      deflating = false;
    }
  } 
  
  else {
    inflating = true;
  }

  if (deflating){
    deflateFinger();
  } else if (inflating){
    inflateFinger(PWM);
  } else {
    // If not inflating or deflating, then the pressure will be maintained.
    maintainFingerPressure();
  }
  //////////////////////////////// END STATECHANGE LOGIC ////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// END MAIN LOOP ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// FUTURE NOTES ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/*
 * Should we control the motor or the exhaust flow?
 * 
 * 
 * 50% fist is where the patient should be.
 * 
 * Below that range, inflate.
 * 
 * At the desired range (50% or 500 something right now, +- a buffer range)
 * 
 * 
 * 
 * 
 */
