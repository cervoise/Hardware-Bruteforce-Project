/*
grep -r "defined(__AVR" | cut -d\( -f 2 | cut -d\) -f 1 | sort | uniq
grep -r "defined(__" | grep -v "AVR" | cut -d\( -f 2 | cut -d\) -f 1 | sort | uniq
*/

//Arduino leonardo et teensy 2
#if defined(__AVR_ATmega32U4__)
  #define arduino 1  
#endif
/*
//Teensy 2++
#if not defined(__AVR_AT90USB1286__)
    #error Sorry dude, this program works only on Arduino 1
#endif

#if not defined(__AVR_AT90USB162__)
    #error Sorry dude, this program works only on Arduino 2
#endif

#if not defined(__AVR_AT90USB646__)
    #error Sorry dude, this program works only on Arduino 3
#endif
*/

//Teensy 3
#if defined(__MK20DX128__)
    #define arduino 3
#endif

//Teensy 3+
#if defined(__MK20DX256__)
    #define arduino 4
#endif

void setup() {
  Serial.begin(9600);  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  if (arduino == 1)
  {
    Serial.println("Leonardo");
  }
  if (arduino == 3)
  {
    Serial.println("Teensy 3");
  }
  if (arduino == 4)
  {
    Serial.println("Teensy 3+");
  }
}

void loop() {}
