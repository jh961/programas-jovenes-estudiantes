/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
const int led = 2;
//const int pot = 14;

int valor = 0;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  if (valor == 0){
    
     digitalWrite(led,HIGH);
     valor =1;
  }else {
     digitalWrite(led,LOW);
     valor =0;
  }
  // read the input on analog pin 0:
  //valor = analogRead(pot);
  // print out the value you read:
 // Serial.println(valor);
  
  //analogWrite(led,valor/4);

  
  
  delay(1000);        // delay in between reads for stability
}
