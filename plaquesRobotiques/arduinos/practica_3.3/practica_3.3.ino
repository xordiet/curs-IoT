const int verm=8, verd=7, PIR=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(verm, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(PIR, INPUT);
  digitalWrite(verm, LOW);
  digitalWrite(verd, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(PIR);
  if (value==HIGH){
    digitalWrite(verm,HIGH);
    digitalWrite(verd, LOW);
  } else {
    digitalWrite(verd,HIGH);
    digitalWrite(verm, LOW);
  }
  delay(1000);
}
