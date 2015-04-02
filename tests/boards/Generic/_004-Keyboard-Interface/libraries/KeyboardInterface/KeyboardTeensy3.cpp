
#if defined(__MK20DX128__) || defined(__MK20DX256__) 
// Implementation for Teensy 3 or 3+

#pragma message("Using Keyboard implementation for Teensy") 

#include "KeyboardInterface.h"

void KeyboardInterface::begin()
{ }

void KeyboardInterface::print(const char* string, int d)
{
	int i;
	for(i=0 ; i<strlen(string) ; i++)
	{
		Keyboard.print(string[i]);
		delay(d);
	}
}

void KeyboardInterface::press(int key)
{
	Keyboard.set_key1(key);
	Keyboard.send_now();
	delay(50);
	Keyboard.set_key1(0);
	Keyboard.send_now();
}

#endif
