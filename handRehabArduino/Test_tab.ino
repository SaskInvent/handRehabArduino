///*
// * Shows that tabs have access to global variables.
// */
//void hasGlobals(){
//  Serial.println(fingerValve);
//}

/*
 * Guidelines:
 *    All seperate files should be written as if they are inline with the main program.
 *    In practice that means:
 *        - no "void setup()" or "void loop()" functions.  They live in the main program. 
 *            - Alternatively, define your own "void myFileSetup()" and "void myFileLoop()" functions. 
 *                - These can then be called from the main program. ### See below ###
 *        - Using global variables (such as pins) to determine behaviour.  That way the 
 *          pin only has to be changed in one place.
 */

/*
 * Call in main "void setup()" function to get desired behaviour.
 */
void testSetup(){
  // Your code here
}

/*
 * Call in main "void loop()" function to get desired behaviour.
 */
void testLoop(){
  // Your code here
}
