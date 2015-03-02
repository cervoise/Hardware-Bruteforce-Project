#include <LiquidCrystal.h>

void passwordTest(const char* password)
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
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

const char *dico[] = { "pass0", "pass1", "pass2", "motdepassetreslong", "passé"};
LiquidCrystal lcd(15, 14, 5, 4, 3, 2);

void setup() {
  delay(1000);
  lcd.begin(16, 2);
}

void loop() {
  int i;
  int j;
  char ligne2[16];
  
delay(500);
for (i=0 ; i < 5; i++)  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(dico[i]);
    if (strlen(dico[i]) > 16)
    {     
      for (j=16 ; j < strlen(dico[i]) && j < 32 ; j++)
      {
        ligne2[j-16] = dico[i][j];
      }
      ligne2[j-16+1] = '\0';
      lcd.setCursor(0, 1);
      lcd.print(ligne2);
    }
    
    passwordTest(dico[i]);
  }
}
