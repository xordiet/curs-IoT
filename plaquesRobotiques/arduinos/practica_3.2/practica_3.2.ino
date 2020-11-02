//defineixo els pins
const int echo=5, tigger=6, verm=9, verd=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(tigger, OUTPUT);
  pinMode(verm, OUTPUT);
  pinMode(verd, OUTPUT);
  digitalWrite(verm, LOW);
  digitalWrite(verd, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cm = ping(tigger, echo);
  if(cm<10){
    digitalWrite(verm, HIGH);
    digitalWrite(verd, LOW);
  } else {
    digitalWrite(verm, LOW);
    digitalWrite(verd,HIGH);
  }
  Serial.print("Distància: ");
  Serial.println(cm);
  delay(1000);
}

//funció per retornar la distància
int ping(int tigger, int echo){
  long duration, distanceCm;
  digitalWrite(tigger, LOW); //ho pausem per obtenir un pols net
  delayMicroseconds(4);
  digitalWrite(tigger, HIGH); //enviem un pols 10 microsegons
  delayMicroseconds(10);
  digitalWrite(tigger, LOW);
  duration = pulseIn(echo, HIGH); //mesurem temps entre polsos
  distanceCm = duration *10 / 292 / 2;
  return distanceCm;
}
