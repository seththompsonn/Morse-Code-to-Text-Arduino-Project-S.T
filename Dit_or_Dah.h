#ifndef Dit_or_Dah_h
#define Dit_or_Dah_h

#if(ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// Header file for the Dot_or_Dah Library.
// Contains Declarations for the methods and variables listed below. 

class Dit_or_Dah
{

  public:
    // Constructor:
    Dit_or_Dah(bool buttonState, bool firstPressDone);

    // Public Methods:
    // Method is used to time how long the input button is held down
    // for or let go for. Depending on how long either is, a specific 
    // value will be returned and stored in an array.
    int Return_Dit_or_Dah();

  private:
    // Private Variables:

    // Digital pin 8 is the pin that will take in the user's high and low inputs from the press of a button.
    const int MORSE_CODE_INPUT_PIN = 8;
    // Like in the main file, the standard time unit is defined to be 1000 milliseconds (1 second)
    const int TIME_UNIT = 1000;
    
    bool highOrLow;
    bool pressedOnce;
};

#endif
