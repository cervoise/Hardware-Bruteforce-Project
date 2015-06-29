#include "PinBruteForce.h"

PinBruteForce::PinBruteForce(int pSize)
{
	size = pSize;
	value = 0;
	limit = powint(10, size) ;
	Serial.println(size) ;
	Serial.println(limit) ;
}

bool PinBruteForce::hasNext()
{
	return value < limit ;
}

char* PinBruteForce::next()
{
	if (!hasNext())
	{
		//TODO: throw an error
	}
	//Serial.println(limit);
	//Serial.println(value);
	return format(value++);	
}

char* PinBruteForce::format(long pValue)
{
  int arraySize = size + 1;
  char *pinCode = (char *) malloc((arraySize) * sizeof(char));
  
  // Fill the array with zeroes to avoid '\n' in the string
  for(int i = 0 ; i < arraySize ; i++) {
    pinCode[i] = '0';
  }

  // Convert pValue to string
  snprintf(pinCode, arraySize, "%d", pValue);

  // Shift string to the right until the last char is '\0'
  while(pinCode[arraySize - 1] != '\0')
  {
    for(int i = arraySize - 2 ; i >= 0 ; i--)
    {
      pinCode[i+1] = pinCode[i];
    }
    pinCode[0] = '0';
  }

  return pinCode;
}

long PinBruteForce::powint(int factor, unsigned int exponent)
{
    long product = 1;
    while (exponent--)
       product *= factor;
    return product;
}
