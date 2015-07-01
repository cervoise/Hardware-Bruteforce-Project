#define DELTA 120

int getX(int pos)
{
  if (pos % 3 == 0)
    return 3;
  return pos % 3;  
}

int getY(int pos)
{
  if (pos < 4 == 0)
    return 1;
  if (pos < 7 == 0)
    return 2;
  return 3;
}

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

//use to go back to origin and to start drawing the pattern
void moveWithoutClic(int origin, int destination)
{
  Mouse.release(MOUSE_ALL);
  int x = getX(destination) - getX(origin);
  int y = getY(destination) - getY(origin);
  mouseMoveX(x);
  mouseMoveY(y);
}

void drawPattern(char* path)
{
  int pathArray[sizeof(path)];
  
  for (int i = 0 ; i < sizeof(path) - 1; i++) {
    pathArray[i] = path[i] - '0';
  }
  
  
  Mouse.release(MOUSE_ALL);
  moveWithoutClic(1, pathArray[0]);
  Mouse.press(1);

  //algo
  for (int i = 0 ; i < sizeof(pathArray) - 2; i++) {
    //same column
    if(getX(pathArray[i]) == getX(pathArray[i+1]))
    {
      mouseMoveY(getY(pathArray[i+1]) - getY(pathArray[i]));
    //same line
    } else if(getY(pathArray[i]) == getY(pathArray[i+1])) {
      mouseMoveX(getX(pathArray[i+1]) - getX(pathArray[i]));
    //diagonal
    } else if( (abs(getX(pathArray[i+1]) - getX(pathArray[i])) == 1) and (abs(getY(pathArray[i+1]) - getY(pathArray[i])) == 1) ) {
      mouseMoveX(getX(pathArray[i+1]) - getX(pathArray[i]), 2);
      mouseMoveY(getY(pathArray[i+1]) - getY(pathArray[i]), 2);
      mouseMoveX(getX(pathArray[i+1]) - getX(pathArray[i]), 2);
      mouseMoveY(getY(pathArray[i+1]) - getY(pathArray[i]), 2);
    // strange diagonal on X
    } else if(abs(getX(pathArray[i+1]) - getX(pathArray[i])) == 2) {
      mouseMoveX(getX(pathArray[i+1]) - getX(pathArray[i]), 2);
      mouseMoveY(getY(pathArray[i+1]) - getY(pathArray[i]));
      mouseMoveX(getX(pathArray[i+1]) - getX(pathArray[i]), 2);
    // stange diagonal on Y
    } else {
      mouseMoveY(getY(pathArray[i+1]) - getY(pathArray[i]), 2);
      mouseMoveX(getX(pathArray[i+1]) - getX(pathArray[i]));
      mouseMoveY(getY(pathArray[i+1]) - getY(pathArray[i]), 2);
    }
  }

  //we release and got back to origin
  Mouse.release(MOUSE_ALL);
  moveWithoutClic(pathArray[sizeof(pathArray) - 1], 1);
}
