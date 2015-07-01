

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
	return dataList.array[pos++];	
}


