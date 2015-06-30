/* Do not use this file !!! Code is not complete */

#define USE_LOGIN false
#define LOGIN_IN_FILES false
//#define USE_PASSWORD true
#define PASSWORD_IN_FILES false

//bruteforce only works for PIN code
#define BRUTEFORCE_PASSWORD false
#define BRUTEFORCE_PIN BRUTEFORCE_PASSWORD

#define ANDROID_PATTERN false

#define CLASSIC_LCD false
//Need LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/
#define LCD16X2 true


#if BRUTEFORCE_PIN
  #include <PinBruteForce.h>
  int bruteForceLength = 4;
#endif

#if LOGIN_IN_FILES or PASSWORD_IN_FILES or ANDROID_PATTERN
  #include <LineByLineReadFiles.h>

  //Ethernet Shield on Uno and SD Shield for Leonardo/Uno use 4
  const int sdCsPin = 4;
  
  #if LOGIN_IN_FILES
    char *loginWordfiles[] = {"login1.txt", "login2.txt"};
    LineByLineReadFiles login(loginWordfiles, sdCsPin);
  #endif
  #if PASSWORDS_IN_FILES
    char *passwordWordfiles[] = {"pass1.txt", "pass2.txt"};
    LineByLineReadFiles password(passwordWordfiles, sdCsPin);
  #endif
#endif

#if USE_LOGIN and not LOGIN_IN_FILES
  #include <LineByLine.h>
  char *loginWordlist[] = {"lorem", "ipsum", "dolor", "sit", "amet"};
  LineByLine login(slice{.array = loginWordlist, .size = sizeof(loginWordlist)});
#endif

#if not BRUTEFORCE_PASSWORD and not PASSWORD_IN_FILES
  #include <LineByLine.h>
  char *passwordWordlist[] = {"lorem", "ipsum", "dolor", "sit", "amet", "test"};
  LineByLine password(slice{.array = passwordWordlist, .size = sizeof(passwordWordlist)});    
#endif

/*
//If there is a limitation (Android: 30s to wait every 5 failed attempts)
int limitTest = 0;
int timeToWait = 5000;
*/

void setup(){
  /*
  int attempt = 0;
  lcdStart();
  
  keyboardStart();

  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(8, INPUT);
  
  delay(5000);
*/
}

void loop(){
/*
  while(!digitalRead(8)) {}

  
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
/*  
   }
   lcdClear();
   while(1) {}
*/
}
