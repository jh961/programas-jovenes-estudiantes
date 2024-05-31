
const int pinled = 2;
const int pinmovi = 3;
void setup() {

  Serial.begin(115200);
  delay(10);
  // put your setup code here, to run once:
  pinMode(pinled, OUTPUT);
  pinMode(pinmovi, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(digitalRead(pinmovi));

  delay(100);

  if(digitalRead(pinmovi)== HIGH){
    digitalWrite(pinled, HIGH);
  }else {
    digitalWrite(pinled, LOW);
  }



}
