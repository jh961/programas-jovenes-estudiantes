#include <IRremote.h>

const int led1 =5;
int RECV_PIN = 11,apa=0,salida=0;
int led11,comp;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
 Serial.begin(9600);
  irrecv.enableIRIn();

}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    pinMode(led1,OUTPUT);
  }

led11=0xE0E06897;
comp = results.value;

 if ((comp== led11)&&(apa==0)){
    digitalWrite(led1, HIGH);
    apa=1;
    results.value=0;
    salida=250;
    }else if((comp== led11)&&(apa==1)) {
      analogWrite(led1, LOW);
      apa=0;
      results.value=0;
      salida=0;
      }

 if ((results.value==0xE0E0E01F)&&(apa==1)){
      
      if ((salida<=250)&&(salida>=0)){
        salida=salida+10;
        Serial.println(salida);
        analogWrite(led1, salida);
         results.value=0;
      } }else if ((results.value==0xE0E0D02F)&&(apa==1)){
      if ((salida<=250)&&(salida>=0)){
        salida=salida-10; 
         Serial.println(salida); 
        analogWrite(led1, salida);
         results.value=0;
      } }
      
      if((salida==260)){
        salida=250;
        analogWrite(led1, salida);
        }else if(salida==-10){
        salida=0;
        analogWrite(led1, salida);
        } 
  delay(100);      
   }


