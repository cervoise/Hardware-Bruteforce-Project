#if LCD_SERIAL
  int buttonPin = BUTTON_PIN;
  
  void lcdPrint(char* inputString) {
    Serial1.println(inputString);
  }
  
  void lcdClear() {
  }
  
  void lcdStart() {
    Serial1.begin(9600);
    pinMode(buttonPin, INPUT_PULLUP);   // Pull-up resistor by the MCU
  }

  void waitButtonPressed()
  {
    while(digitalRead(buttonPin) == LOW)  
    { 
      delay(10);  // Wait for button release
    }

    while(digitalRead(buttonPin) == HIGH) 
    { 
      delay(10);  // Wait for button release
    }

    // Button pressed : exit this function !
    return;
  }

  //This is not working yet
  void pauseWithButton()
  {
    /*if(lcd.readButtons() & !0x02) {
      lcdPrint("Attack paused");
      waitButtonPressed();
    }*/
  }
#endif

