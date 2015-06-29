//OLIMEXINO-328 + SHIELD-LCD16x2

/*
 * 
 * 
 */

#include <LCD16x2.h>
#include <Wire.h>

LCD16x2 lcd;

int buttons;

void setup(){
  Wire.begin();
  lcd.lcdClear();  
}
void loop(){
  buttons = lcd.readButtons();
  lcd.lcdGoToXY(1,1);
  while(buttons & 0x01){
    buttons = lcd.readButtons();
    }  
  
  lcd.lcdWrite("Run attack");
  
  while(1) {}
}
