#include <LiquidCrystal.h>

//Crea l'objete LCD amb els núms assignats (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int EchoPin = 9;
const int TriggerPin = 10;

void setup(){
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  // Inicialitzo l'LCD amb el nombre de fileres i columnes
  lcd.begin(16, 2);
  // Escric el missatge inicial.
  lcd.setCursor(0, 0);
  lcd.print("Hola Mon!");
  lcd.setCursor(0, 1);
  lcd.print("Hello World!");
  delay(1000);
}

void loop(){
  lcd.clear();
  int cm = ping(TriggerPin, EchoPin);
  Serial.print("Distancia: ");
  Serial.println(cm);
  lcd.setCursor(0, 0);
  lcd.print("Distancia:");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  lcd.print(" cm.");
  delay(1000);
}

//funció que em retorna la distància
int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;
  digitalWrite(TriggerPin, LOW); //per obtenir un pols net el posem LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH); //generem el Trigger de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  duration = pulseIn(EchoPin, HIGH); //mesurem el temps entre polsos, en microsegons
  distanceCm = duration * 10 / 292/ 2; //calculem la distància, en cm
  return distanceCm;
}
