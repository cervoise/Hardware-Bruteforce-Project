#if not LCD16X2 and BUTTON
  void waitButtonPressed()
  {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    while(!digitalRead(BUTTON_PIN)) {}
  }
#endif
