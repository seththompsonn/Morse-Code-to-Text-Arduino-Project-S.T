#ifndef Character_LUT_h
#define Character_LUT_h

#if(ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// Header file for the Character_LUT Library
// Defines Constructor and the Return_Character method

class Character_LUT
{
  public:
    //Constructor:
    // No variables need to be brought into this to work.
    Character_LUT();
    //Public methods:
    // Declaration for the look-up table that will
    // take in the sequence of Dits and Dahs from earlier and return
    // the appropriate charaacter to be output to the LCD display.
    char Return_Character(int data[6]);
  private:
    //Private Variables

    // Private Methods
};

#endif
