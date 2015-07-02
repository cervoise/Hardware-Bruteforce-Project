

#include "LineByLine.h"

LineByLine::LineByLine(slice pDataList)
{
	dataList = pDataList;
}

void LineByLine::init()
{
	pos = 0;
}

bool LineByLine::hasNext()
{
	return pos < (int) dataList.size;
}

char* LineByLine::next()
{
	if (!hasNext())
	{
		//TODO: throw an error
	}
	
	char *line = dataList.array[pos++];
	
	// Initialize a char* with malloc, because the user expects to do a free() with the char returned by next()
	char *res = (char*) malloc((strlen(line) + 1) * sizeof(char));
	strcpy(line, res);
	
	return res;	
}


