/*
  Arduino code for clutch and 
  handbrake to Logitech DFGT wheel
  Potentiometer version

  For Arduino Leonardo/Micro
  Ronaldo Rezende Jr (@naldin)
  ronaldo.rrj at gmail.com
  09/2018
  https://github.com/naldin/DFGT_Clutch
  http://xyzturbo.blogspot.com

  ----------------------------------------

  Joystick.h
  https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-1.0

  Hardware made with 3D printer
  https://www.thingiverse.com/thing:671536
  https://www.thingiverse.com/thing:2994189
*/

#include "Joystick.h"

//variable
int val;   //clutch
int val2; //handbrake

//constants
const int analogIn = A0; //clutch
const int analogIn2 = A1;//handbrake
const int minPot = 235;
const int maxPot = 360;

void setup() {
  Joystick.begin(); //Start joystick mode
}

void loop() {

  //clutch
  val = analogRead(analogIn); //read analog value
  val = map(val, minPot, maxPot, 0, 255); //mapping value between min and max pot value
  val = constrain(val, 0, 255); // Constrains min and max range between 0 and 255

  //handbrake
  val2 = analogRead(analogIn2);
  val2 = map(val2, 0, 1023, 0, 255);

  // use the desired option
  Joystick.setThrottle(val); //clutch
  //Joystick.setZAxis(val2);
  Joystick.setRudder(val2);  //handbrake
}
