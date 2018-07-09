/*
  Arduino code for clutch
  to Logitech DFGT wheel
  Potentiometer version

  For Arduino Leonardo/Micro
  Ronaldo Rezende Jr (@naldin)
  ronaldo.rrj at gmail.com
  07/2018
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
int val;

//constants
const int analogIn = A0;
const int minPot = 235;
const int maxPot = 360;

void setup() {
  Joystick.begin(); //Start joystick mode
}

void loop() {
  val = analogRead(analogIn); //read analog value
  val = map(val, minPot, maxPot, 0, 255); //mapping value between min and max pot value
  val = constrain(val, 0, 255); // Constrains min and max range between 0 and 255

  // use the desired option
  Joystick.setThrottle(val);
  //Joystick.setZAxis(val);
  //Joystick.setRudder(val);
}
