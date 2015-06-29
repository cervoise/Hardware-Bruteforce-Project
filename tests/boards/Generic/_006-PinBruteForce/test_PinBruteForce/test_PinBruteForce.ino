#include <PinBruteForce.h>

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  delay(1500);
  Serial.println("start");

  PinBruteForce p(5);

  while(p.hasNext())
  {
    char *pass = p.next();
    Serial.println(pass);
    //delay(10);
    free(pass);
  }

  Serial.println("Finish");
}

void loop() {
  

}
