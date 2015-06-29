#ifndef PinBruteForce_h
#define PinBruteForce_h

#include <Arduino.h>

class PinBruteForce {
	public:
		PinBruteForce(int);
		bool hasNext();
		char* next();
		
	protected:
		long value;
		int size;
		long limit;
		char* format(long);
		long powint(int, unsigned int);
};

#endif
