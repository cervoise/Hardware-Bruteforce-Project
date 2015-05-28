
#include <Arduino.h>
//#include <SPI.h>
#include <SD.h>

class LineByLine {
	public:
		LineByLine(char*[]);
		
		bool hasNext();
		char* next();
		
	protected:
		void init(char*[]);
		
		char *dataList[];
		int pos = -1;
		
};
