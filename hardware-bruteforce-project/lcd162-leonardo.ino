#include <LCD16x2.h>
#include <Wire.h>

LCD16x2 lcd;

void lcdStart() {
	lcd.lcdClear();
}

void lcdPrint(char* inputString) {
        lcd.lcdGoToXY(1,1);
        lcd.lcdWrite(inputString);
}

void lcdClear()
{
	lcd.lcdClear();
}
