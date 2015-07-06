//Need Leonardo with modify HID.cpp (see: http://www.zem.fr/utiliser-mouse-keyboard-azerty-arduino-pro-micro-teensy/)
//Need LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/

#include <LCD16x2.h>
#include <Wire.h>
#include <SD.h>

LCD16x2 lcd;
int buttons;

void pT(char* password) {
  delay(150);
  int j;
  for (j = 0 ; j < strlen(password) ; j++) {
    Keyboard.print(password[j]);
    delay(100);
  }
  delay(150);
}

void setup() {
  Keyboard.begin();
  Wire.begin();
  lcd.lcdClear();
  pinMode(10, OUTPUT);
}

void loop() {
  int i;
  int j;
  int k;
  int l;
  int m;
  
  String pincodeString;
  char pincodeChar[5];
  
  buttons = lcd.readButtons();
  for (i=0 ; i<10; i++)
    for (j=0; j<10; j++)
      for (k=0; k<10; k++)
        for (l=0; l<10; l++) {
          pincodeString = String(i) + String(j) + String(k) + String(l);
          pincodeString.toCharArray(pincodeChar, 5);
          lcd.lcdClear();
          lcd.lcdGoToXY(1,1);
          lcd.lcdWrite(pincodeChar);
          pT(pincodeChar);
             
          delay(250);
          for (m=0; m < 4 ; m++) {
            Keyboard.press(KEY_BACKSPACE);
            delay(50);
            Keyboard.releaseAll();
          } 
        }
  while(1){}   
}
