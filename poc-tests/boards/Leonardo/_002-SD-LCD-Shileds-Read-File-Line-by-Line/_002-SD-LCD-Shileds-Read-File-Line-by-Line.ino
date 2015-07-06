//Need LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/
//SD shield for test: http://www.lextronic.fr/P28726-platine-sd-card-shield-v40-pour-arduino.html

#include <LCD16x2.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>

LCD16x2 lcd;

int buttons;
File myFile;

char inputString [100];
char inputChar;
int stringIndex = 0; 

void setup(){
  Wire.begin();

  lcd.lcdClear();
  pinMode(10, OUTPUT);
  if (!SD.begin(4)) {
    return;
  }

  // re-open the file for reading:
  myFile = SD.open("file1.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      inputChar = myFile.read(); // Gets one byte from serial buffer
      if (inputChar != '\n') // define breaking char here (\n isnt working for some reason, i will follow this up later)
      {
        inputString[stringIndex] = inputChar; // Store it
        stringIndex++; // Increment where to write next
      }
      else  
      {
        stringIndex = 0; // clear the value for the next cycle
        lcd.lcdClear();
        lcd.lcdGoToXY(2,1);

        lcd.lcdWrite(inputString);
        delay (1000);
      }
   }
    // close the file:
    myFile.close();
  } 
}

void loop(){}
