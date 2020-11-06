#include <NewPing.h>

const int verm=8;
const int groc=9;
const int blau=10;
const int verd=11;
const int PIRPin= 7;
const int TriggerPin = 6;
const int EchoPin = 5;
const int MaxDistance = 200;

NewPing sonar(TriggerPin, EchoPin, MaxDistance);

void setup(){
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
  int value= digitalRead(PIRPin);
  if (value == HIGH){
    digitalWrite(verm, HIGH);
    digitalWrite(verd, LOW);
    delay(1000);
  } else {
    digitalWrite(verm, LOW);
    digitalWrite(verd, HIGH);
    delay(1000);
  }
}
