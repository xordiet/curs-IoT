#include <NewPing.h>

const int verm=8;
const int groc=9;
const int blau=10;
const int verd=11;
const int PIRPin= 7;
const int TriggerPin = 6;
const int EchoPin = 5;
const int MaxDistance = 200;
const int prox = 10;

NewPing sonar(TriggerPin, EchoPin, MaxDistance);

void setup(){
  Serial.begin(9600);
  pinMode(verm, OUTPUT);
  pinMode(groc, OUTPUT);
  pinMode(blau, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(PIRPin, INPUT);
  digitalWrite(verm, LOW);
  digitalWrite(groc, LOW);
  digitalWrite(blau, LOW);
  digitalWrite(verd, LOW);
}

void loop(){
  delay(1000);
  
  int value= digitalRead(PIRPin);
  int cm = sonar.ping_cm();
  if (value == HIGH && cm > prox){ // només el PIR = blau
    digitalWrite(verm, LOW);
    digitalWrite(groc, LOW);
    digitalWrite(blau, HIGH);
    digitalWrite(verd, LOW);
  } else if(value == LOW && cm < prox) { // només el HC-SR04 = groc
    digitalWrite(verm, LOW);
    digitalWrite(groc, HIGH);
    digitalWrite(blau, LOW);
    digitalWrite(verd, LOW);
  } else if(value == HIGH && cm < prox) { // els dos = vermell
    digitalWrite(verm, HIGH);
    digitalWrite(groc, LOW);
    digitalWrite(blau, LOW);
    digitalWrite(verd, LOW);
  } else { // cap = verd
    digitalWrite(verm, LOW);
    digitalWrite(groc, LOW);
    digitalWrite(blau, LOW);
    digitalWrite(verd, HIGH);
  }
  Serial.print(value);
  Serial.print(" - ");
  Serial.print(cm);
  Serial.println("");
}
