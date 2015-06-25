

#include "LineByLineReadFiles.h"

#define LINE_MAX_LENGTH 50


LineByLineReadFiles::LineByLineReadFiles(slice pDataList, int pin) : LineByLine(pDataList)
{
	if (!SD.begin(pin)) {
		//TODO: throw an error
	}
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
	char line[LINE_MAX_LENGTH];
	while (i == 0 || line[i-1] != '\n')
	{
		// Check that char position doesn't exceed max length
		if (i < LINE_MAX_LENGTH)
		{
			line[i] = currentFile.read();
		}
		
		i++;
	}

	if (i < LINE_MAX_LENGTH)
	{
		line[LINE_MAX_LENGTH-1] = '\0';
	}
	else
	{
		line[i-1] = '\0';
	}

	return line;
}

