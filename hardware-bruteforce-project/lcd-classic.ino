#if CLASSIC_LCD

  #include <LiquidCrystal.h>
  
  //for Teensy
  LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

  void lcdPrint(char* inputString) {
    lcd.setCursor(0, 0);
    lcd.print(password);
  }
  
  void lcdClear() {
    lcd.clear();
  }

  void lcdStart() {
    lcd.begin(16, 2);
  }
#endif
