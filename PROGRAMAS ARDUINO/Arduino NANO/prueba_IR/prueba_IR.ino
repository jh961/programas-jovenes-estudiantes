/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

const int led1 =5;
const int led2 =6;
const int led3 =9;

int RECV_PIN = 11,apa=0,apa1=0,apa2=0,salida=0,salida1=0,salida2=0;
int led11,led22,led33,comp;
int gua1,gua2,gua3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
  } 

  
  led11=0xE0E06897;
  led22=0xE0E0C837;
  led33=0xE0E028D7;

  comp = results.value;
  
  if ((comp== led11)&&(apa==0)){
    digitalWrite(led1, HIGH);
    apa=1;
    gua1=comp;
    gua2=0;
    gua3=0;
    results.value=0;
    salida=250;
    }else if((comp== led11)&&(apa==1)) {
      analogWrite(led1, LOW);
      apa=0;
      results.value=0;
      salida=0;
      }

     if ((comp== led22)&&(apa1==0)){
    digitalWrite(led2, HIGH);
    apa1=1;
    gua2=comp;
    gua1=0;
    gua3=0;
    results.value=0;
    salida1=250;
    }else if((comp== led22)&&(apa1==1)) {
      analogWrite(led2, LOW);
      apa1=0;
      results.value=0;
      salida1=0;
      }

      if ((comp== led33)&&(apa2==0)){
    digitalWrite(led3, HIGH);
    apa2=1;
    gua3=comp;
    gua2=0;
    gua1=0;
    results.value=0;
    salida2=250;
    }else if((comp== led33)&&(apa2==1)) {
      analogWrite(led3, LOW);
      apa2=0;
      results.value=0;
      salida2=0;
      }   
    
    if ((results.value==0xE0E0E01F)&&(apa==1)&&(gua1== led11)){
      
      if ((salida<=250)&&(salida>=0)){
        salida=salida+10;
        Serial.println(salida);
        analogWrite(led1, salida);
         results.value=0;
      } }else if ((results.value==0xE0E0D02F)&&(apa==1)&&(gua1== led11)){
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
