#include "IRremote.h"

const int relPin = 3;
const int ikPin = 4;
bool stat = true;
IRrecv irrecv(ikPin); // указываем вывод, к которому подключен приемник
decode_results results;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(relPin, OUTPUT);
}

void blink(int times) {
  for (times; times > 0; times --){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(20);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(20); 
  }
}
void loop() {
  
  if ( irrecv.decode( &results )) {
      int res = results.value;
      Serial.println( stat );
      Serial.println( res, HEX ); // print data
      
      if (res == 0x52AD){
          blink(3);
          if (stat == true ){
            digitalWrite(relPin, HIGH);
            stat = false;
          }
          else {
            digitalWrite(relPin, LOW);
            stat = true;
          }
      }
      irrecv.resume(); // get next command
  }
}
