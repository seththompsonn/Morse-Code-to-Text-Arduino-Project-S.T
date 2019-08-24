# Morse-Code-to-Text-Arduino-Project-S.T
This code allows the user to input a Morse code signal with a 
button connected to an Arduino Uno and output the combination 
of dits and dahs as text on a LCD screen.

** This project is NOT YET COMPLETE, but it still works as is.
All that is left is a small amount of debugging and fine tuning.

** KNOWN BUGS: 
- There are times where the '2' variable will not return (Which represents 'newditordah').
- The first character outputted to the LCD display is, usually, wrong.


** IMPROVEMENTS TO BE MADE:
- Adding in a RESET button and START button. Only possible way to
reset the system as is is to press the reset button on the Arduino UNO
- Use of enumerators in librarys as opposed to just returning integer values
for improved readabillity.
- Adding in the use of both rows of a 2x16 LCD display as opposed to just 
using one row.

