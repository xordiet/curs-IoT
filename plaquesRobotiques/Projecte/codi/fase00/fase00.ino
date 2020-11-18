int latch1 = 8;      // ST_CP (12) al 74HC595 front
int clock1 = 13;     // SH_CP (11) al 74HC595 front
int dataP1 = 12;     // DS    (14) al 74HC595 front

int actmt = 9; // pin que activara o no els motors
int camin = 0; // variable que dirà en quina direcció aniran els motors
int veloc = 255; // velocitat del vehicle

byte data = 0; //dada que rebrem del port sèrie

void updateShiftRegister(byte fron){
   shiftOut(dataP1, clock1, LSBFIRST, fron);
}

void moume(byte data){
  Serial.print("moume: ");
  Serial.println(data, BIN);
  //analogWrite(actmt, veloc);
  digitalWrite(actmt, HIGH);
  digitalWrite(latch1, LOW);
  for (int i = 0; i < 8; i++){
    updateShiftRegister(data);
  }
  digitalWrite(latch1, HIGH);
}
void aturam(){
  Serial.println("aturam!");
  digitalWrite(actmt, LOW);
  digitalWrite(latch1, LOW);
  for (int i = 0; i < 8; i++){
    updateShiftRegister(0);
  }
  digitalWrite(latch1, HIGH);
}

void setup()
{
  pinMode(latch1, OUTPUT);
  pinMode(clock1, OUTPUT);
  pinMode(dataP1, OUTPUT);
  pinMode(actmt, OUTPUT);
  digitalWrite(latch1, LOW);
  digitalWrite(actmt, LOW);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available() > 0){
      data = Serial.parseInt();
      Serial.println("rebut!");
      Serial.print(data);
      Serial.print(": ");
      Serial.println(data, BIN);
      if (data==0){
        //aturam();
      } else {
        //aturam();
        //delay(10);
        moume(data);
      }
  }
}
