int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595

void updateShiftRegister(byte leds){
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
}


void imprimeixText(String text){
  for(int i=0; i < text.length(); i++){
      char data = text.charAt(i);

      Serial.print(data);
      Serial.print(": ");
      Serial.println(data, BIN);

      digitalWrite(latchPin, LOW);
      for (int j = 0; j < 8; j++){
        updateShiftRegister(data);
      }
      digitalWrite(latchPin, HIGH);
      delay(2000);
   }
}

void apagarho(){
  byte r = 0;
  digitalWrite(latchPin, LOW);
  updateShiftRegister(r);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  digitalWrite(latchPin, LOW);
  Serial.begin(9600);
}

void loop() { 
  if (Serial.available()){
    String text = Serial.readStringUntil('\n');
    imprimeixText(text);
    delay(10000);
    //apaga-ho tot
    apagarho();
  }
}
