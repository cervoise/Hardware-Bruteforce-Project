
#ifndef LineByLine_h
#define LineByLine_h

#include <Arduino.h>

struct slice {
	char** array;
	size_t size;
};

class LineByLine {
	public:
		LineByLine(slice);
		void init();
		
		bool hasNext();
		char* next();
		
	protected:
		slice dataList;
		int pos = 0;
};

#endif

