

#include "LineByLine.h"

LineByLine::LineByLine(char *dataList[])
{
	dataList = dataList;
}

bool LineByLine::hasNext()
{
	return pos < sizeof(dataList);
}

char* LineByLine::next()
{
	if (!hasNext())
	{
		//TODO: throw an error
	} 
	return dataList[++pos];	
}


