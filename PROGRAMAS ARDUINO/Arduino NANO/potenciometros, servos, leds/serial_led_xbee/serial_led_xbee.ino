#include <IRremote.h>
#include <IRremoteInt.h>

/*
 -------------------------------------- 
  Escritura serial
 --------------------------------------
 
  Consiste en escribir por la pantalla del computador (consola serial) 
   una letra predeterminada, la primera vez que se escriba está 
   un LED se enciende, si se vuelve a escribir por segunda vez 
   el LED se apaga.
 
 Cosas de Mecatrónica y Tienda de Robótica
 
*/
 
//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int led = 5;           //Pin donde se encuentra el LED, salida
char leer;              //Variable donde se almacena la letra 
boolean prendido=false; //Estado LED la primera vez, apagado 
 
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  Serial.begin(9600);    //Inicia comunicación serial
  pinMode(led, OUTPUT);  //Configurar el LED como una salida
}
 
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{           //  cuando este energizado el Arduino 
 
  //Guardar en una variable el valor de la consola serial
  leer=Serial.read();
 
  // Si es la letra 'a' y además el LED está apagado
  if ( (leer=='a') && (prendido==false) )
  {
      digitalWrite(led,HIGH);  // Enciende el LED
      prendido=true;
      delay(1000);
      Serial.print("@Hola#");
      //Serial.send(1);
      }          // Actualiza el estado del LED 
  // Si es la letra 'a' y además el LED está encendido
  else if ( (leer=='a') && (prendido==true) )
  {
      digitalWrite(led,LOW);   // Apaga el LED 
      prendido=false;
      delay(1000);
      Serial.print("@Chao#");
      //Serial.send(0); 
      // Actualiza el estado del LED 
  }  
 
}
 
//Fin programa
