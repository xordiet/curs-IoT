int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595

//byte leds = 196; // numero entre 0 i 255 que el programa mostra el seu binari en forma de leds encesos o apagats
int incomingByte = 0; 

void updateShiftRegister(byte leds){
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
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
      int data = Serial.parseInt();
      Serial.println(data);

      digitalWrite(latchPin, LOW);
      for (int i = 0; i < 8; i++){
        updateShiftRegister(data);
      }
      digitalWrite(latchPin, HIGH);
   }
}
