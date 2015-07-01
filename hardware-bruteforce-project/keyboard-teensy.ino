#if defined(__MK20DX128__) or defined(__MK20DX256__)
  void keyboardStart()
  {
     Keyboard.begin();
  }
  
  void typePassword(char * testPassword)
  {
     Keyboard.print(testPassword);
  }

  void typeKey(int key)
  {
    Keyboard.set_key1(key);
    Keyboard.send_now();
  }
  
  void typeEnter()
  {
     typeKey(KEY_ENTER);
  }

  void typeBackspace()
  {
     typeKey(KEY_BACKSPACE);
  }

  void typeTab()
  {
     typeKey(KEY_TAB);
  }

#endif