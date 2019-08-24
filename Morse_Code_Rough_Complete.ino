// Name: Seth Thompson
// New test to see if I can get the system to return the character that needs to be output to the LCD display.

#include "Dit_or_Dah.h"
#include "Character_LUT.h"
#include <LiquidCrystal.h>

/*
   IMPORTANT NOTES:
   "dit" = 1 time unit
   "dah" = 3 time units
   Space between parts of the same letter = 1 time unit
   Space between letters = 3 time units
   Space between words = 7 time units
   Time unit can be set manually, for now time unit = 1 second
*/

// Setting up global variables
const int START_STOP_INPUT_PIN = 7;
const int RESET_INPUT_PIN = 6;
const int MORSE_CODE_INPUT_PIN = 8;
const int TIME_UNIT = 1000;
// Variable firstPressDone tells the system whether or not the button has been pressed at least once so that the first output
// of the system is a dit or dah and not the other three options.
bool firstPressDone = false;
// The array next stores the results of each variable returned from the Dit_or_Dah library
int elements[6] = {0, 0, 0, 0, 0, 0};
int i = 0;

// Notes on LCD pins:
/*
   1: logic Ground (Ground)
   2: Logic Live (+5V)
   3: V0 (Potentiometer Output)
   4: RS (Digital 12)
   5: RW (Ground)
   6: E (Digital 11)
   11: D4 (Digital Pin 5)
   12: D5 (Digital Pin 4)
   13: D6 (Digital Pin 3)
   14: D7 (Digital Pin 2)
   15: Backlight Live (+5V)
   16: BackLight Ground (Ground)
*/

// Declaring all global variables and initializing the LCD display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int NumRows = 2;
const int NumColumns = 16;

void setup() {
  // Setting up button input pin and preparing serial moniter for debugging
  pinMode(MORSE_CODE_INPUT_PIN, INPUT);

  // Preparing the LCD display
  lcd.begin(NumColumns, NumRows);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {

  // creating a boolean variable buttonState to determine whether the morse code input button
  // is being held down or not, this will be passed into the Dit_or_Dah object.
  bool buttonState;
  // As soon as the button is pressed once, set the firstPressDone variable to true so the low inputs 
  // may start to be timed. Also set the button state to high or low depending on when the button is pressed 
  // or not.
  if (digitalRead(MORSE_CODE_INPUT_PIN))
  {
    buttonState = true;
    firstPressDone = true;
  }
  if (!digitalRead(MORSE_CODE_INPUT_PIN) && firstPressDone)
  {
    buttonState = false;
  }

  // Creating a dit or dah object. Bring in the state of the button and the 
  // firstPressDone flag.
  Dit_or_Dah result(buttonState, firstPressDone);

  // Storing the result in a variable to bring into a LUT (look-up table).
  int comparator = result.Return_Dit_or_Dah();

  // 
  if (comparator == 0) { //store a dit as a 0
    elements[i] = comparator;
    i++;
  }

  if (comparator == 1) { //store a dah as a 1
    elements[i] = comparator;
    i++;
  }

  if (comparator == 2) { //newditordah
    //Do nothing, this is used as an intermediate between dits and dahs.
  }

  if (comparator == 3) { // new letter
    //print off contents of array and then clear it
    elements[i] = comparator;
    Character_LUT character1;
    // A new letter must be entered after this, get the letter needed, output it to the LCD...
    char output1 = character1.Return_Character(elements);
    Serial.print("Array: ");
    for (int j = 0; j < sizeof(elements) / sizeof(elements[0]); j++)
    {
      Serial.print(elements[j]);
    }
    Serial.print("\n");
    Serial.print("Character: ");
    Serial.println(output1);
    lcd.print(output1);

    // ... and then clear the array to make room for the next composition of dits andd dahs.
    for (int j = 0; j < sizeof(elements) / sizeof(elements[0]); j++)
    {
      elements[j] = 0;
    }
    i = 0;
  }

  if (comparator == 4) { // new word
    //print off contents of array and then clear it
    // Also add a space to LCD display
    elements[i] = comparator;
    Character_LUT character2; // Very much the same procedure as when comparator is 3, except also print a space on the LCD as well.
    char output2 = character2.Return_Character(elements);
    Serial.print("Array: ");
    for (int j = 0; j < sizeof(elements) / sizeof(elements[0]); j++)
    {
      Serial.print(elements[j]);
    }
    Serial.print("\n");
    Serial.print("Character: ");
    Serial.println(output2);
    lcd.print(output2);
    lcd.print(" ");

    for (int j = 0; j < sizeof(elements) / sizeof(elements[0]); j++)
    {
      elements[j] = 0;
    }
    i = 0;
  }

  // If i reaches the end of the array, set it back to the start
  if (i >= sizeof(elements) / sizeof(elements[0]))
  {
    i = 0;
  }

}
