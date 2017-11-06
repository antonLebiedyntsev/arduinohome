#include "IRremote.h"

const int relPin = 3;
const int ikPin = 6;
bool stat = true;
IRrecv irrecv(ikPin); // указываем вывод, к которому подключен приемник

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(relPin, OUTPUT);
}

void loop() {
  if ( irrecv.decode( &results )) { // data came
      Serial.println( stat );
      Serial.println( results.value); // print data
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
