void setup() {
  Keyboard.begin();
}

void loop() {
    Keyboard.print("This is a string");
    Keyboard.press(KEY_RETURN);
    delay(50);
    Keyboard.releaseAll();
    while(1) {}
}
