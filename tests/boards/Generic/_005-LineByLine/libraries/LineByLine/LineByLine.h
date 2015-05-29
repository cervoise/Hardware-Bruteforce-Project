
#include <Arduino.h>
//#include <SPI.h>
#include <SD.h>

class LineByLine {
	public:
		LineByLine(char*[]);
		
		bool hasNext();
		char* next();
		
	protected:
		char *dataList[];
		int pos = -1;
		
};
