void attack(char* aPassword, char* aLogin = "", int delayLoginChange = 0)
{
  drawPattern(aPassword);
  delay(1000);
}

void initMouse()
{
  //mouseMove(2,0);
}

//this function is used to made the system wait when system is lock (like on Android, 30s every 5 failed attempt)lorem
void waitFunction()
{
  typeEnter();
  for (int k = 0; k < 12; k++)
  {
    typeEnter();
    delay(2500);
  }
}

