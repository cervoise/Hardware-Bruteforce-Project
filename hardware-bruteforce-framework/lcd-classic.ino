#if LCD_KEYPAD_MODULE
  #define CLASSIC_LCD true
#endif

#if CLASSIC_LCD
 #if LCD_KEYPAD_MODULE
    #define LCD_RS 8
    #define LCD_E 9
    #define LCD_D4 4
    #define LCD_D5 5
    #define LCD_D6 6
    #define LCD_D7 7
  #endif
  
  #include <LiquidCrystal.h>
  
  //for Teensy
  LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

  void lcdPrint(char* inputString) {
    lcd.setCursor(0, 0);
    lcd.print(inputString);
  }
  
  void lcdClear() {
    lcd.clear();
  }

  void lcdStart() {
    lcd.begin(16, 2);
  }
#endif
