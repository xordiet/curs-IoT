#include <NewPing.h>

const int TriggerPin = 6;
const int EchoPin = 5;
const int MaxDistance = 200;
const int verm=9;
const int verd=10;

NewPing sonar(TriggerPin, EchoPin, MaxDistance);

void setup() {
  Serial.begin(9600);
  pinMode(verm, OUTPUT);
  pinMode(verd, OUTPUT);
  digitalWrite(verm, LOW);
  digitalWrite(verd, LOW);
}

void loop() {
  delay(1000); // esperar 50ms entre pings (29ms como minimo)
  if(sonar.ping_cm() < 10){
    digitalWrite(verm, HIGH);
    digitalWrite(verd, LOW);
  } else {
    digitalWrite(verm, LOW);
    digitalWrite(verd, HIGH);
  }
  Serial.print(sonar.ping_cm()); // obtener el valor en cm (0 = fuera de rango)
  Serial.println("cm");
}
