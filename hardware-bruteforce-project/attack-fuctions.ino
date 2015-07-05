void attack(char* aPassword, char* aLogin = "", int delayLoginChange = 0)
{
  int j;
  /* for (j = 0 ; j < strlen(aLogin) ; j++) {
    typeLetter(aLogin[j]);
    delay(100);
  }
  typeEnter();
  */
  for (j = 0 ; j < strlen(aPassword) ; j++) {
    typeLetter(aPassword[j]);
    delay(100);
  }
  typeEnter();
  //drawPattern(aPassword);
  delay(1500);
  delay(delayLoginChange);

}

void initMouse()
{
  //moveWithoutClic(2, 1);
  Mouse.press(1);
}

//this function is used to made the system wait when system is lock (like on Android, 30s every 5 failed attempt)lorem
void waitFunction()
{

}
