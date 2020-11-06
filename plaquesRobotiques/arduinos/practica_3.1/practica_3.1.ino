int analogpin = A0, val = 0, pin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogpin);
  Serial.println(val);
  if(val < 100){
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
  delay(20);
}
