#include <LiquidCrystal.h>

void pressEnter() {
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void passwordTest(const char* password, int enter) {
  delay(150);
  int j;
  for (j = 0 ; j < strlen(password) ; j++) {
    Keyboard.print(password[j]);
    delay(100);
  }
  for (j = 0; j < enter; j++) {
    delay(150);
    pressEnter();	
  }
}

void lcdShowPassword(const char* password, LiquidCrystal lcd) {
  int j;
  char line2[16];
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(password);
  if (strlen(password) > 16) {     
    for (j=16 ; j < 32 ; j++) {
      //We add the password letter on the second line, if there is no more letter we fill with blank
      if (j < strlen(password)) {
	    line2[j-16] = password[j];
      }
      else {
        line2[j-16]= ' ';
      }
    }
    //line2[j-16+1] = '\0';
    lcd.setCursor(0, 1);
    lcd.print(line2);
  }
}

const char *dico[] = { "pass0", "pass1", "pass2", "motdepassetreslong", "passé"};
LiquidCrystal lcd(15, 14, 5, 4, 3, 2);

#define USELCD 0

void setup() {
  delay(1000);
  if(USELCD != 0) {
     lcd.begin(16, 2);
  }
}

void loop() {
  int i;
  int passwordNumber;
  passwordNumber = sizeof(dico)/sizeof(char *);
  delay(500);
  for (i=0 ; i < passwordNumber; i++)  {
    if(USELCD != 0) {
       lcdShowPassword(dico[i], lcd);
    }
	passwordTest(dico[i], 2);
  }
}

