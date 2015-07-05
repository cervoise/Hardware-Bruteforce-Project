#if defined(__AVR_ATmega32U4__) and LCD16X2
  #include <LCD16x2.h>
  #include <Wire.h>
  
  LCD16x2 lcd;

  void lcdPrint(char* inputString) {
    lcd.lcdGoToXY(1,1);
    lcd.lcdWrite(inputString);
  }
  
  void lcdClear() {
  	lcd.lcdClear();
  }

  void lcdStart() {
    Wire.begin();
    lcdClear();
  }

  void waitButtonPressed()
  {
    while(lcd.readButtons() & 0x01){} //It's nice, isn't it. 
  }

  //This is not working yet
  void pauseWithButton()
  {
    if(lcd.readButtons() & !0x02) {
      lcdPrint("Attack paused");
      waitButtonPressed();
    }
  }
#endif
