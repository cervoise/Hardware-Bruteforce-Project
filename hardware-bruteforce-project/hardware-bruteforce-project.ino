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
//If you want to use another button with the LCD16X2 go to hell
#if not LCD16X2
  #define BUTTON true
  #define BUTTON_PIN 8
#endif

#if CLASSIC_LCD
  #define LCD_RS 15
  #define LCD_E 14
  #define LCD_D4 5
  #define LCD_D5 4
  #define LCD_D6 3
  #define LCD_D7 2
#endif

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
    LineByLineReadFiles login(slice{.array = loginWordfiles, .size = sizeof(loginWordfiles)}, sdCsPin);
  #endif
  #if PASSWORDS_IN_FILES
    char *passwordWordfiles[] = {"pass1.txt", "pass2.txt"};
    LineByLineReadFiles password(slice{.array = passwordWordfiles, .size = sizeof(passwordWordfiles)}, sdCsPin);
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


#if not LCD16X2 and not CLASSIC_LCD
  void lcdStart() {}
  void lcdPrint(char*) {}
  void lcdClear() {}
#else
  void lcdStart();
  void lcdPrint(char*);
  void lcdClear();
#endif

void keyboardStart();
void typePassword(char*);
void typeEnter();
void typeReturn();
void typeTab();
void waitButtonPressed();

//this function is used in order to allow to add delay between each letter (for slow UEFI) and so on
void cutPassword(char* aPassword)
{

}

//this function is used to made the system wait when system is lock (like on Android, 30s every 5 failed attempt)
//for exemple on ... you have to type TAB 10 times to get back
void waitFunction()
{

}

  int attempt = 0;
  bool limit = true;
  int limitTest = 5;

void setup() {
  lcdStart();
  keyboardStart();

  lcdPrint("Start: button1");
  waitButtonPressed();
  lcdClear();
}

void loop(){

while(password.hasNext()) {
  if(limit and attempt == limitTest) {
    waitFunction();
    attempt = 0;
  } else {
    char* testedPassword = password.next();
    lcdClear();
    lcdPrint(testedPassword);
    cutPassword(testedPassword);
    attempt++;
  }
}

   lcdClear();
   lcdPrint("Attack ended");
   while(1) {}

}
