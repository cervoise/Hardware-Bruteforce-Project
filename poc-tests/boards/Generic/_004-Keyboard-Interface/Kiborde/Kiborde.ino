#include <KeyboardInterface.h>

KeyboardInterface kiborde;

void setup()
{
  kiborde.begin();
}

void loop()
{
  kiborde.print("Hello Keyboard!", 250);
  
  while(true){}
}
