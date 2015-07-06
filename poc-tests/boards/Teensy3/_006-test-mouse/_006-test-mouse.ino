void setup() {
  Mouse.screenSize(1080, 724);  // configure screen size
}

void loop() {
  int x = 500;
  int y = 160;
  Mouse.moveTo(50, 50);       // point to pixel at 25, 100
  Mouse.set_buttons(1, 0, 0);  // hold left button
  Mouse.moveTo(60, 60);         // move the mouse while holding
  delay(5);
  Mouse.moveTo(70, 70);  
  delay(5);
  Mouse.set_buttons(0, 0, 0); 
}
