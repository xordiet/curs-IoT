int latch1 = 8;      // ST_CP (12) al 74HC595 front
int clock1 = 13;     // SH_CP (11) al 74HC595 front
int dataP1 = 12;     // DS    (14) al 74HC595 front

int fron = 0; // variable que envia quins pins encendre als motors davanters
int tras = 0; // variable que envia quins pins encendre als motors darrers

void updateShiftRegister(byte fron){
   shiftOut(dataP1, clock1, LSBFIRST, fron);
}

void setup()
{
  pinMode(latch1, OUTPUT);
  pinMode(clock1, OUTPUT);
  pinMode(dataP1, OUTPUT);
  digitalWrite(latch1, LOW);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()){
      int data = Serial.parseInt();
      Serial.print(data);
      Serial.print(": ");
      Serial.println(data, BIN);

      fron = data;
   }

  digitalWrite(latch1, LOW);
  for (int i = 0; i < 8; i++){
    updateShiftRegister(fron);
  }
  digitalWrite(latch1, HIGH);
}
