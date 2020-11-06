//defineixo els pins que usaré
const int EchoPin = 5;
const int TriggerPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  }

void loop() {
  int cm = ping(TriggerPin, EchoPin);
  Serial.print("Distancia: ");
  Serial.println(cm);
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
