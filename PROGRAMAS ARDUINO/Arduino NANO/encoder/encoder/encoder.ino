


int pul = 4;
int pin = 0;
int pulsos = 0;

void setup() {
 pinMode(pul,INPUT);
  Serial.begin(9600);
}

void loop() {
  //pin = digitalRead(pul);
  
  if(digitalRead(pul)==HIGH){
  pulsos++; 
  while(digitalRead(pul)==HIGH){}
  }
  Serial.print(pulsos);
  Serial.println(" pulsos");
  
  //delay(100);
}
