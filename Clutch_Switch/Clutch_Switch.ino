/*
  Arduino code for clutch
  to Logitech DFGT wheel
  Switch version
  
  For Arduino Leonardo/Micro
  Ronaldo Rezende Jr (@naldin)
  ronaldo.rrj at gmail.com
  07/2018
  https://github.com/naldin/DFGT_Clutch
  http://xyzturbo.blogspot.com

  ----------------------------------------
  
  keyboard.h
  https://www.arduino.cc/en/Tutorial/KeyboardSerial

  Hardware made with 3D printer
  https://www.thingiverse.com/thing:671536
  https://www.thingiverse.com/thing:2994189
*/

#include "Keyboard.h"

//constants
const int switchClutch = 4;
const int debounceDelay = 10;
const char charClutch = 'x'; //Use the letter desired

void setup() {
  //setup port
  pinMode(switchClutch, INPUT);
  //start keyboard
  Keyboard.begin();
}

void loop() {
  if (digitalRead(switchClutch) == HIGH) {
    delay(debounceDelay); //For debounce
    if (digitalRead(switchClutch) == LOW) { //For debounce
      Keyboard.write(charClutch); //send char
    }
  }
}

