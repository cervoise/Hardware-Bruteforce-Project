void keyboardStart()
{
   Keyboard.begin();
}

void typePassword(char * testPassword)
{
   Keyboard.print(testPassword);
}

void typeSpecial(int key)
{
   Keyboard.press(key);
   delay(50);
   Keyboard.releaseAll();
}

