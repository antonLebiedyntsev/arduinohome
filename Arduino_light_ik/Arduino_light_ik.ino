#include "IRremote.h"

const int relPin = 3;
const int ikPin = 6;
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
      delay(40);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(40); 
  }
}
void loop() {
  
  if ( irrecv.decode( &results )) { // data came
      Serial.println( stat );
      Serial.println( results.value); // print data
      blink(3);
      if ( results.value == 4294967295 ){
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
