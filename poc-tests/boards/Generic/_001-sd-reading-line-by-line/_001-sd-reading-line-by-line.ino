#include <LiquidCrystal.h>
#include <SD.h>
//do not know why, but compilation failed without SPI.h
#include <SPI.h>

LiquidCrystal lcd(15, 14, 5, 4, 3, 2);
File myFile;

void setup() {
  //SS Pin four OUTPUT
  pinMode(10, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  //lcdShowPassword("Init SD", lcd);
  if (!SD.begin(10)) {
    lcd.print("Init failed");
    return;
  }
  lcd.print("init ok");
  myFile = SD.open("test.txt");
  if (myFile) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("test.txt");
    while (myFile.available()) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(myFile.read());
    }
    myFile.close();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("error open");
  }
}

void loop() {
}
