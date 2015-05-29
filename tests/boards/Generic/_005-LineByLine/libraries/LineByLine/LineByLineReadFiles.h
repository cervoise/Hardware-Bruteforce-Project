

#include "LineByLine.h"

#include <SD.h>
#include <SPI.h>

class LineByLineReadFiles : public LineByLine {
	public:
		LineByLineReadFiles(char*[], int);
		bool hasNext();
		char* next();
		
	protected:
		File currentFile;
		
};
