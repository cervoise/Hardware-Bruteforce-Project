#if defined(__AVR_ATmega32U4__)

  void keyboardStart()
  {
     Keyboard.begin();
  }
  
  void typePassword(char * testPassword)
  {
     Keyboard.print(testPassword);
  }
  
  void typeSpecial(int key)
  {
     Keyboard.press(key);
     delay(50);
     Keyboard.releaseAll();
  }

#endif
