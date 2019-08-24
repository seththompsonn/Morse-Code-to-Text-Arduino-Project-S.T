#if(ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Character_LUT.h"

// This whole library takes the array made in the main file and returns the character that needs to be output to the LCD

// Defining the constructor.
Character_LUT::Character_LUT()
{
  // Nothing to instansiate.
}

// Methods:

char Character_LUT::Return_Character(int data[6])
{
  int counter = 0;
  int i = 0;

  // This for loop is used to determine how large a second array should be to store all of the elements that matter to the LUT.
  // Once a 3 or 4 is reached, the counter stops and that will be the arrays size
  for (;;)
  {
    if (data[i] == 3 || data[i] == 4)
    {
      break;
    }
    else
    {
      i++;
    }
  }


  // instanciate that array and fill it with the contents of the array brought into this library from the main file.
  int LUTArray[i];
  
  for (int j = 0; j < i; j++)
  {
    LUTArray[j] = data[j];
  }

  // This variable calculates the size of the newly made array
  int sizeofLUTarray = sizeof(LUTArray) / sizeof(LUTArray[0]);

  // Enter a switch case statement that has five different LUT's
  // Depending on the size of the LUTArray and its contents, a specific character will be returned to the main file 
  // and then printed to the LCD display.
  switch (sizeofLUTarray)
  {
    case 1:
      if (LUTArray[0] == 0)
      {
        return 'E';
      }
      else if (LUTArray[0] == 1)
      {
        return 'T';
      }
      break;
    case 2:
      if (LUTArray[0] == 0 && LUTArray[1] == 1)
      {
        return 'A';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0)
      {
        return 'I';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1)
      {
        return 'M';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 0)
      {
        return 'N';
      }
      break;
    case 3:
      if (LUTArray[0] == 1 && LUTArray[1] == 0 && LUTArray[2] == 0)
      {
        return 'D';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 0)
      {
        return 'G';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 0 && LUTArray[2] == 1)
      {
        return 'K';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 1)
      {
        return 'O';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 1 && LUTArray[2] == 0)
      {
        return 'R';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 0)
      {
        return 'S';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 1)
      {
        return 'U';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 1 && LUTArray[2] == 1)
      {
        return 'W';
      }
      break;
    case 4:
      if (LUTArray[0] == 1 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 0)
      {
        return 'B';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 0 && LUTArray[2] == 1 && LUTArray[3] == 0)
      {
        return 'C';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 1 && LUTArray[3] == 0)
      {
        return 'F';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 0)
      {
        return 'H';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 1 && LUTArray[2] == 1 && LUTArray[3] == 1)
      {
        return 'J';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 1 && LUTArray[2] == 0 && LUTArray[3] == 0)
      {
        return 'L';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 1 && LUTArray[2] == 1 && LUTArray[3] == 0)
      {
        return 'P';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 0 && LUTArray[3] == 1)
      {
        return 'Q';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 1)
      {
        return 'V';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 1)
      {
        return 'X';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 0 && LUTArray[2] == 1 && LUTArray[3] == 1)
      {
        return 'Y';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 0 && LUTArray[3] == 0)
      {
        return 'Z';
      }
      break;
    case 5:
      if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 1 && LUTArray[3] == 1 && LUTArray[4] == 1)
      {
        return '0';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 1 && LUTArray[2] == 1 && LUTArray[3] == 1 && LUTArray[4] == 1)
      {
        return '1';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 1 && LUTArray[3] == 1 && LUTArray[4] == 1)
      {
        return '2';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 1 && LUTArray[4] == 1)
      {
        return '3';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 0 && LUTArray[4] == 1)
      {
        return '4';
      }
      else if (LUTArray[0] == 0 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 0 && LUTArray[4] == 0)
      {
        return '5';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 0 && LUTArray[2] == 0 && LUTArray[3] == 0 && LUTArray[4] == 0)
      {
        return '6';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 0 && LUTArray[3] == 0 && LUTArray[4] == 0)
      {
        return '7';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 1 && LUTArray[3] == 0 && LUTArray[4] == 0)
      {
        return '8';
      }
      else if (LUTArray[0] == 1 && LUTArray[1] == 1 && LUTArray[2] == 1 && LUTArray[3] == 1 && LUTArray[4] == 0)
      {
        return '9';
      }
      break;
  }



}
