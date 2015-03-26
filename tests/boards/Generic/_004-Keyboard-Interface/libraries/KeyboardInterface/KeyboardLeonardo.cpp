
#if defined (__AVR_ATmega32U4__) && not defined CORE_TEENSY
// Implementation for Arduino Leonardo

#pragma message("Using Keyboard implementation for Leonardo") 

#include "KeyboardInterface.h"

void KeyboardInterface::begin()
{
	Keyboard.begin();
}

void KeyboardInterface::print(char* string, int d)
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
	Keyboard.press(key);
	delay(50);
	Keyboard.releaseAll();
}

#endif
