

#ifndef KeyboardInterface_h
#define KeyboardInterface_h

#include <Arduino.h>

class KeyboardInterface
{
	public:
		void begin();
		void print(char*, int);
		void press(int);
};


#endif



