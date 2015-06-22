

#include "LineByLine.h"

LineByLine::LineByLine(char **pDataList)
{
	dataList = pDataList;
}

bool LineByLine::hasNext()
{
	return pos < (int) sizeof(dataList);
}

char* LineByLine::next()
{
	if (!hasNext())
	{
		//TODO: throw an error
	} 
	return dataList[++pos];	
}


