const int button = 5;
const int led =2;

int buttonlectura = 0;

void setup() {
  // put your setup code here, to run once:
  
pinMode(led,OUTPUT);

pinMode(button, INPUT);
}

void loop() {

buttonlectura = digitalRead(button);
  if (buttonlectura == HIGH){
 digitalWrite(led, HIGH);
 delay(1000);
  digitalWrite(led, LOW);
 delay(1000);
 }
  else{
 digitalWrite(led, LOW);
 //delay(1000);
 }
 
}
