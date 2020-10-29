int analogPin = A0, val = 0, pin= 13;

void setup(){
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);
  if (val > 800) {
    digitalWrite(pin,HIGH);
  } 
  else {
    digitalWrite(pin,LOW);
  }
  delay(20);// debug value
}
