void setup() {
  int a = 1;
  int b = 2;
  Serial.begin(9600);  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println(test(a,b));
}

void loop() {}
