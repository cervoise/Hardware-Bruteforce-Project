

#include "LineByLineReadFiles.h"

#define LINE_MAX_LENGTH 50


LineByLineReadFiles::LineByLineReadFiles(slice pDataList, int pin) : LineByLine(pDataList)
{
	if (!SD.begin(pin)) {
		//TODO: throw an error
	}
}

void LineByLineReadFiles::init()
{
	LineByLine::init();
}


bool LineByLineReadFiles::hasNext()
{
	if (currentFile && currentFile.available())
	{
		return true;
	}
	else
	{
		if (currentFile)
		{
			// Close currently open file before switching to the next
			currentFile.close();
		}

		// Check whether a next file exists
		if (!LineByLine::hasNext())
		{
			return false;
		}

		currentFile = SD.open(LineByLine::next());
		if (!currentFile)
		{
			//TODO: log error while opening file dataList.array[pos]	
		}

		return hasNext();
	}
}

char* LineByLineReadFiles::next()
{
	if (!hasNext())
	{
		//TODO: throw an error
	}

	// Arghh, we can't read lines directly: we need to reinvent the wheel
	int i = 0;
	char c;
	char *line = (char*) malloc((LINE_MAX_LENGTH + 1) * sizeof(char));
	while ((c=currentFile.read()) != '\n')
	{
		if (i < LINE_MAX_LENGTH)
		{
			line[i] = c;
			 i++;
		}
	}

	line[i] = '\0';

	return line;
}

