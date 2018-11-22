
/**
 * Time from the millis() function MUST be read into and compared to unsigned longs.
 * Mathematical operations on other datatypes can lead to unpredictable behaviour.
 */
unsigned long time_millis;  // Current time on each loop iteration.
unsigned long continuous_delta_time;   // Change in time from frame to frame.
unsigned long one_second_delta_time;   // Change in time from frame to frame.
unsigned long two_second_delta_time;   // Change in time from frame to frame.
unsigned long maximum_rate_of_change = 50;  // TEMP/TESTING value.
unsigned long continuous_sample_rate;       // 
unsigned long one_second_rate;
unsigned long two_second_rate;

// TEMP/TESTING 
unsigned long continuous_delta;
unsigned long one_second_delta;
unsigned long two_second_delta;


void setup(){
  Serial.begin(9600);
  while(!Serial){
    Serial.println("Waiting");
  }
  Serial.println("Setting up");
}


void loop(){
  Serial.print("Looping ");
  testingTimeFunctions();
}


void testingTimeFunctions(){

  Serial.print("size of unsigned long: ");
  Serial.print(sizeof(time_millis));
  time_millis = millis();

  // TEMP/TESTING
  // NOT A PROPER IMPLEMENTATION!!

  // 3 sampling levels:
  //
  // As often as possible.
  
  
  continuous_delta_time = time_millis - one_second_delta_time;

  continuous_sample_rate = true_flex * continuous_delta_time;

  Serial.print("One second delta time: ");
  Serial.print(continuous_delta_time);
  Serial.print("One second rate change: ");
  Serial.print(continuous_sample_rate);
  
  if(time_millis % 2000 == 0){
    // TODO: this
    // DO WE HAVE TO WORRY ABOUT OVERFLOWS WHEN CALCULATING RATES?
    
    
    // 1000 milli seconds is 1 second.
    one_second_delta_time = time_millis / 1000 - one_second_delta_time;
    two_second_delta_time = time_millis / 2000 - two_second_delta_time;
    // How much has the flex changed in the last second?
    one_second_rate = true_flex * one_second_delta_time;
    two_second_rate = true_flex * two_second_delta_time;
    // calculate rate of change using the delta_time(sss) from the previous loop.
    
    Serial.print("two second delta time: ");
    Serial.print(two_second_delta_time);
    Serial.print("two second rate change: ");
    Serial.print(two_second_rate);
    Serial.print("one second delta time: ");
    Serial.print(one_second_delta_time);
    Serial.print("one second rate change: ");
    Serial.print(one_second_rate);

    
  } else if (time_millis % 1000 == 0){
    // 1000 milli seconds is 1 second.
    one_second_delta_time = time_millis / 1000 - one_second_delta_time;
    // How much has the flex changed in the last second?
    one_second_rate = true_flex * one_second_delta_time;
    Serial.print("One second delta time: ");
    Serial.print(one_second_delta_time);
    Serial.print("One second rate change: ");
    Serial.print(one_second_rate);
  }
  
  Serial.print(" milli seconds unsigned long is: ");
  Serial.println(time_millis);
}
