int red = 7;
int green = 8;
int boton = 11;
 
void setup()
{
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(boton, INPUT);
 
//Creamos la interrupcion
attachInterrupt(0, alarma, RISING);
}
 
void loop()
{
digitalWrite(green, HIGH);
delay(1000);
digitalWrite(green, LOW);
delay(200);
}
 
//Codigo de la interrupcion
void alarma()
{
digitalWrite(green, LOW);
while(digitalRead(boton) == HIGH)
{
digitalWrite(red, HIGH);
delay(200);
digitalWrite(red, LOW);
delay(200);
}
}
