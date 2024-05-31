
int triger = 2;
int echo = 3;
int led = 4;

float tiempo;
float distancia;


void setup() {
  pinMode(triger,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(triger,LOW);
  delayMicroseconds(2);
  
  digitalWrite(triger,HIGH);
  delayMicroseconds(10);
  
  tiempo = pulseIn(echo,HIGH);
  distancia = ((tiempo/2)/30);
  Serial.print(distancia);
  Serial.println("cm");
  delay(100);


  if (distancia >=10){
    digitalWrite(led,HIGH);
  }else {
     digitalWrite(led,LOW);
  }
  }
  


