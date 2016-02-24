#if LCD16X2 or LCD_KEYPAD_MODULE
  #define BUTTON true
#endif

#if not ( LCD16X2 or LCD_SERIAL ) and BUTTON
  #if LCD_KEYPAD_MODULE
  int  adc_key_val[5] ={30, 150, 360, 535, 760 };
  int NUM_KEYS = 5;

  // Convert ADC value to key number
  int get_key(unsigned int input)
  {
    int k;
      
    for (k = 0; k < NUM_KEYS; k++) {
      if (input < adc_key_val[k]) {
        return k;
      }
    }
      
    if (k >= NUM_KEYS)
      k = -1;     // No valid key pressed
      
    return k;
  }
  
  void waitButtonPressed()
  {
    while(get_key(analogRead(0)) < 0) {}
  }
 
  #else
  void waitButtonPressed()
  {
    pinMode(BUTTON_PIN, INPUT);
    while(!digitalRead(BUTTON_PIN)) {}
  }
  #endif
#endif
