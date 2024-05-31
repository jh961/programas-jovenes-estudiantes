#include <IRremote.h>

const int led1 =5;
int RECV_PIN = 11,salida=0;
int prender,apagar,comp,subir,bajar;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
 Serial.begin(9600);
  irrecv.enableIRIn();

}
void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    irrecv.resume();
    pinMode(led1,OUTPUT);
  }

prender=0xF7C03F;
apagar=0xF740BF;
subir=0xF700FF;
bajar=0xF7807F;
comp = results.value;

 if ((comp== prender)){
    digitalWrite(led1, HIGH);
    results.value=0;
    salida=255;
    Serial.println("a");
    }else if((comp== apagar)) {
      analogWrite(led1, LOW);
      results.value=0;
      salida=0;
      Serial.println("a");
      }

 if ((comp==subir)){
      
      if ((salida<=255)&&(salida>=0)){
        salida=salida+15;
        //Serial.println(salida);
        analogWrite(led1, salida);
        results.value=0;
      } } else if ((comp==bajar)){
            if ((salida<=255)&&(salida>=0)){
              salida=salida-15; 
              //Serial.println(salida); 
              analogWrite(led1, salida);
              results.value=0;
      } }
      
      if((salida==270)){
        salida=255;
        analogWrite(led1, salida);
        }else if(salida==-15){
          salida=0;
          analogWrite(led1, salida);
        } 
  delay(100);      
   }


