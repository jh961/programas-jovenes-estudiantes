
const int led =2;
const int pot = 10;

int brillo ;

void setup() {
  // put your setup code here, to run once:
 pinMode(led, OUTPUT);
 //pinMode(pot, INPUT);
}

void loop() {

  brillo = digitalRead(pot) /2; //0-1023 dividir el valor para analogWrite
  digitalWrite(led , brillo);
  

}
