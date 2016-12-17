/* YourDuino.com Example Software Sketch
   Small Stepper Motor and Driver V1.4 11/30/2013
   http://arduino-direct.com/sunshop/index.php?l=product_detail&p=126
   Steps one revolution of output shaft, then back
   terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Stepper.h>
#include <Wire.h>

/*-----( Declare Constants, Pin Numbers )-----*/
//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  
 

/*-----( Declare objects )-----*/
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

//The pin connections need to be 4 pins connected
// to Motor Driver In1, In2, In3, In4  and then the pins entered
// here in the sequence 1-3-2-4 for proper sequencing
Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

/*-----( Declare Variables )-----*/
int  Steps2Take;

void receiveEvent() {
  while (1 < Wire.available()) { // loop through all but the last
    int c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  
  if(x==1){
  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION ;  // Rotate CW 1 turn
  small_stepper.setSpeed(500);   
  small_stepper.step(Steps2Take);
  }
  else{
    
  }
  Serial.println(x);         // print the integer
}

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Serial.begin(115200);           // start serial for output
}

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  delay(100);
}/* --(end main loop )-- */

/* ( THE END ) */

