//#if defined(__AVR_ATmega32U4__) and ANDROID_PATTERN
#if ANDROID_PATTERN
#define DELTA 120

int getX(int pos)
{
//    Keyboard.print("pos:");
//  Keyboard.print(pos);
  if (pos % 3 == 0)
    return 3;
  return pos % 3;  
}

int getY(int pos)
{
//  Keyboard.print("pos:");
//  Keyboard.print(pos);
  if (pos < 4)
    return 1;
  if (pos < 7)
    return 2;
  return 3;
}

/*
//  Move the mouse in the x axis, negative mouseX = left, postitive mouseX = right
void mouseMoveX(int mouseX, int division = 1) {
  for (int delta = DELTA / division; delta > 0; delta--) {    
    Mouse.move(mouseX, 0, 0);
    delay(5);
  }
}

//  Move the mouse in the Y axis, negative mouseY = up, postitive mouseY = down
void mouseMoveY(int mouseY, int division = 1) {
  for (int delta = DELTA / division; delta > 0; delta--) { 
    Mouse.move(0, mouseY, 0);
    delay(5);
  }
}
*/

void mouseMove(int mouseX, int mouseY) {
   for (int delta = DELTA; delta > 0; delta--) { 
    Mouse.move(mouseX, mouseY, 0);
    delay(5);
  }
}

//use to go back to origin and to start drawing the pattern
void moveWithoutClic(int origin, int destination)
{
  Mouse.release(MOUSE_ALL);
  mouseMove(getX(destination) - getX(origin), getY(destination) - getY(origin));
}

void drawPattern(char* path)
{
  int pathArray[strlen(path)];

  //strlen do not return the \0
  for (int i = 0 ; i < strlen(path); i++) {
    pathArray[i] = path[i] - '0';
  }

  moveWithoutClic(1, pathArray[0]);
  Mouse.release(MOUSE_ALL);
  Mouse.press(1);
  
  for (int i = 0 ; i < strlen(path) - 1; i++) {
    mouseMove(getX(pathArray[i+1]) - getX(pathArray[i]), getY(pathArray[i+1]) - getY(pathArray[i]));
  }

  //we release and got back to origin
  Mouse.release(MOUSE_ALL);
  moveWithoutClic(pathArray[strlen(path) - 1], 1);
}
#endif
