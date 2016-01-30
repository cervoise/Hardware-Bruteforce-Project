#include <Wire.h>

#define SLAVE_ADDRESS 0x45
int number = 0;
int state = 0;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT); // LED
  
  Wire.begin(SLAVE_ADDRESS);

  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  for(int i=0 ; i<4 ; i++) {
    doBlink();
  }
}

// callback for received data
void receiveData(int byteCount){

    while(Wire.available()) {
        number = Wire.read();
        
        doBlink();

        Keyboard.print(char(number));
     }
}

// callback for sending data
void sendData(){
    Wire.write(number);
}

void doBlink() {
    digitalWrite(LED_BUILTIN,HIGH); 
    delay(300);                     
    digitalWrite(LED_BUILTIN,LOW);
    delay(300);
}

void loop() {
    delay(100);
}
