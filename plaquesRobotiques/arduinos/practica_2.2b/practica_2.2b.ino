#include <NewPing.h>

const int TriggerPin = 6;
const int EchoPin = 5;
const int MaxDistance = 200;

NewPing sonar(TriggerPin, EchoPin, MaxDistance);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000); // esperar 50ms entre pings (29ms como minimo)
  Serial.print(sonar.ping_cm()); // obtener el valor en cm (0 = fuera de rango)
  Serial.println("cm");
}
