
#include "IRremote.h"
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0xCF6A91DA){
      Serial.println("1 clicked");
    }
    irrecv.resume();
  }
  delay(100);
}
