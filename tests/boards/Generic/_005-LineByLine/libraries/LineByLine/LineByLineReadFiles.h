
#ifndef LineByLineReadFiles_h
#define LineByLineReadFiles_h

#include "LineByLine.h"

#include <SD.h>
#include <SPI.h>

class LineByLineReadFiles : public LineByLine {
	public:
		LineByLineReadFiles(slice, int);
		void init();

		bool hasNext();
		char* next();
		
	protected:
		File currentFile;
		
};

#endif

