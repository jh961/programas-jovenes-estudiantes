#include <Servo.h>


Servo miServo;
const int pulsadorMano =7;
const int pulsadorabrir =8;
//const int led = 5;
const int servo1 = 3;
const int pulsomin =600 ;   //angulo 0
const int pulsomax =2600;   //angulo 180

int flat=0;

void setup() {
 pinMode(servo1  ,OUTPUT);
 pinMode(pulsadorMano  ,INPUT);
 pinMode(pulsadorabrir  ,INPUT);
 miServo.attach(servo1, pulsomin, pulsomax);
 miServo.write(0);
}

void loop() {
  if(digitalRead(pulsadorabrir)==HIGH){
    if(flat==1){
        for (int i = 179; i > 0; i--){
         // Desplazamos al ángulo correspondiente
         miServo.write(i);
         // Hacemos una pausa de 25ms
         delay(10);
       }
         flat=0;
    }
    miServo.write(0);
    delay(1000);
  }else{
  if(digitalRead(pulsadorMano)==HIGH){
     /*
      if(flat==0){
       for (int i = 0; i <= 180; i++) {
        // Desplazamos al ángulo correspondiente
        miServo.write(i);
        // Hacemos una pausa de 25ms
        delay(25);
       }
        flat=1;
      }
      */
      delay(500);
      flat=1;
     miServo.write(180);
  }else{
     // Para el sentido negativo
     if(flat==1){
        for (int i = 179; i > 0; i--){
         // Desplazamos al ángulo correspondiente
         miServo.write(i);
         // Hacemos una pausa de 25ms
         delay(10);
          if(digitalRead(pulsadorMano)==HIGH){
            break;
          }
         }
         flat=0;
    }
     if(digitalRead(pulsadorMano)==LOW){
           miServo.write(0);
          }
    
  }
  }
  
}
