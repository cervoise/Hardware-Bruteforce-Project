#ifndef PinBruteForce_h
#define PinBruteForce_h

#include <Arduino.h>

class PinBruteForce {
	public:
		PinBruteForce(int);
		bool hasNext();
		char* next();
		
	protected:
		unsigned long value;
		int size;
		unsigned long limit;
		char* format(unsigned long);
		unsigned long powint(unsigned int, unsigned int);
};

#endif
