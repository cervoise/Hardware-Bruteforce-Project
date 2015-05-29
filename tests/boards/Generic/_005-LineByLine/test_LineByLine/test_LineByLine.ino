/*

* For reading files, SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
*/

// CS pin for SD card
const int sdCsPin = 4;

// Set value to true if wordlist actually is a list of files
#define READ_LINE_BY_LINE_IN_FILES false

#include <SPI.h>
#include <SD.h>


#ifdef READ_LINE_BY_LINE_IN_FILES
  #include <LineByLineReadFiles.h>
  char *wordfiles[] = {"file1.txt", "file2.txt"};
  LineByLineReadFiles lineByLine(wordfiles, sdCsPin);
#else
  #include <LineByLine.h>
  char *wordlist[] = {"lorem", "ipsum", "dolor", "sit", "amet"};
  LineByLine lineByLine(wordlist);
#endif

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
}

void loop() {
  while(lineByLine.hasNext()) {
    Serial.println(lineByLine.next());
  }
}
