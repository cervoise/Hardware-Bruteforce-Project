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

const char *dico[] = { "pass0", "pass1", "pass2"};

void setup() {
  delay(1000);
}

void loop() {
  int i;

for (i=0 ; i < 3; i++)  {
    passwordTest(dico[i]);
    delay(500);
  }
}
