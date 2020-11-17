int latch1 = 8;      // ST_CP (12) al 74HC595 front
int clock1 = 13;     // SH_CP (11) al 74HC595 front
int dataP1 = 12;     // DS    (14) al 74HC595 front

int actmt1 = 2, actmt2 = 3, actmt3 = 4, actmt4 = 5; // pins que activara o no els motors
int camin = 128; // variable que dirà en quina direcció aniran els motors (cap a dreta)
int veloc = 255; // velocitat del vehicle

byte data = 0; //dada que rebrem del port sèrie

void updateShiftRegister(byte fron){
   shiftOut(dataP1, clock1, LSBFIRST, fron);
}

void moume(byte data){
  //Serial.println(data, BIN);
  //analogWrite(actmt, veloc);
  digitalWrite(actmt1, HIGH);
  digitalWrite(actmt2, HIGH);
  digitalWrite(actmt3, HIGH);
  digitalWrite(actmt4, HIGH);
  digitalWrite(latch1, LOW);
  for (int i = 0; i < 8; i++){
    updateShiftRegister(data);
  }
  digitalWrite(latch1, HIGH);
}

void setup()
{
  pinMode(latch1, OUTPUT);
  pinMode(clock1, OUTPUT);
  pinMode(dataP1, OUTPUT);
  pinMode(actmt1, OUTPUT);
  pinMode(actmt2, OUTPUT);
  pinMode(actmt3, OUTPUT);
  pinMode(actmt4, OUTPUT);
  digitalWrite(latch1, LOW);
  digitalWrite(actmt1, LOW);
  digitalWrite(actmt2, LOW);
  digitalWrite(actmt3, LOW);
  digitalWrite(actmt4, LOW);
  //Serial.begin(9600);
}

void loop(){
  /*if (Serial.available()){
      data = Serial.parseInt();
      Serial.print(data);
      Serial.print(": ");
      Serial.println(data, BIN);
      moume(data);
  }*/
  moume(camin);
}
