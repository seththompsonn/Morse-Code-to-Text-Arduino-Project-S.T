#if(ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Dit_or_Dah.h"

Dit_or_Dah::Dit_or_Dah(bool buttonState, bool firstPressDone)
{
  // highOrLow will, quite literally, be high when the button is held down and low when the button is let go.
  highOrLow = buttonState;
  // This variable is used as a flag. Without it, the arduino would start timing how long the button has been
  // let go for before anyone has even pressed it once, which shouldnt happen. This flag prevents this.
  pressedOnce = firstPressDone;
}

Dit_or_Dah::Return_Dit_or_Dah()
{ 
  // high timer are used to store an integer value (in milliseconds) that represents how long the button was held down for or let go for.
  int hightimer = 0;
  int lowtimer = 0;
  // the resulut variable will be returned to the main file and stored in an array.
  int result;

  if (highOrLow)
  { //While the button is being held down, increment the high timer by one millisecond
    while (digitalRead(MORSE_CODE_INPUT_PIN))
    {
      delay(1);
      hightimer += 1;
    }
  }
  else if (!highOrLow)
  { // Else, time how long the button has been let go for
    while (!digitalRead(MORSE_CODE_INPUT_PIN))
    {
      delay(1);
      lowtimer += 1;
    }
  }

  // After one high timer or low timer is done timing, head down to this
  // LUT (look-up table) and return the integer that corresponds to the correct
  // input

  // Minimum time  to be checked against it set to 40 milliseconds to act as a debounceing system for the input,
  // any input recorder as <=40 milliseconds is most likely a false reading. Also, 0.1 seconds have been added
  // to the far limit of each boundary to account for human error while trying to perfectly input a dit or dah.
  if (hightimer > 40 && hightimer <= (TIME_UNIT + 100))
  {
    result = 0;
    Serial.print("dit"); Serial.print(" "); Serial.println(hightimer);
  }
  else if (hightimer > (TIME_UNIT + 100) && hightimer <= ((3 * TIME_UNIT) + 100))
  {
    result = 1;
    Serial.print("dah"); Serial.print(" "); Serial.println(hightimer);
  }
  else if (hightimer > ((3 * TIME_UNIT) + 100))
  { // If the timer has exceeded 3000 milliseconds, default to sending back a 2 since that is what was probably intended.
    result = 1;
    Serial.print("dah"); Serial.print(" "); Serial.println(hightimer);
  }

  // This part of the LUT will only go through if the pressed once flag has been set to true. other than that this
  // LUT acts in the same was as the previous one, with the excetion of the flag and the fact that lowtimer is being compared now.

  // However, for some reason when adding the delay to the first if statement here, an error is returned. I cannot figure out why this is and
  // will fix it at a later time.
  if (lowtimer > 40 && lowtimer <= TIME_UNIT && pressedOnce)
  {
    result = 2;
    Serial.print("newditordah"); Serial.print(" "); Serial.println(lowtimer);
  }
  else if (lowtimer > TIME_UNIT && lowtimer <= ((3 * TIME_UNIT + 100)) && pressedOnce)
  {
    result = 3;
    Serial.print("newletter"); Serial.print(" "); Serial.println(lowtimer);
  }
  else if (lowtimer > ((TIME_UNIT * 3) + 100) && lowtimer <= ((7 * TIME_UNIT) + 100) && pressedOnce)
  {
    result = 4;
    Serial.print("newword"); Serial.print(" "); Serial.println(lowtimer);
  }
  else if (lowtimer > ((TIME_UNIT * 7) + 100) && pressedOnce)
  { // If the timer has exceeded 7000 milliseconds, default to sending back a 4 since that is what was probably intended.
    result = 4;
    Serial.print("newword"); Serial.print(" "); Serial.println(lowtimer);
  }

  return result;
}
