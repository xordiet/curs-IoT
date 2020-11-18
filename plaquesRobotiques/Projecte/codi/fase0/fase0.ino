int latch1 = 8;      // ST_CP (12) al 74HC595 front
int clock1 = 13;     // SH_CP (11) al 74HC595 front
int dataP1 = 12;     // DS    (14) al 74HC595 front

int actmt = 9; // pins que activara o no els motors
int camin = 153; // variable que dirà en quina direcció aniran els motors
int veloc = 255; // velocitat del vehicle (no la uso per ara)

/**
 * 
 * Variables de gir dels motors
 * 
 * -------------------------------------------------------------------
 * | direcció |        davanters      |        darrera        | suma |
 * -------------------------------------------------------------------
 * |          |    de     |     dd    |    re     |     rd    |      |
 * -------------------------------------------------------------------
 * |          | dea | deb | dda | ddb | rea | reb | rda | rdb |      |
 * -------------------------------------------------------------------
 * | endavant |  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  |  170 |
 * -------------------------------------------------------------------
 * | gir dret |  1  |  0  |  0  |  1  |  1  |  0  |  0  |  1  |  153 |
 * -------------------------------------------------------------------
 * | gir esq. |  0  |  1  |  1  |  0  |  0  |  1  |  1  |  0  |  102 |
 * -------------------------------------------------------------------
 * | enrrere  |  0  |  1  |  0  |  1  |  0  |  1  |  0  |  1  |   85 |
 * -------------------------------------------------------------------
 * | a sumar  | 128 |  64 |  32 |  16 |  8  |  4  |  2  |  1  |      |
 * -------------------------------------------------------------------
 * 
 */


byte data = 0; //dada que rebrem del port sèrie

void updateShiftRegister(byte fron){
   shiftOut(dataP1, clock1, LSBFIRST, fron);
}

void moume(byte data){
  //Serial.println(data, BIN);
  //analogWrite(actmt, veloc);
  digitalWrite(actmt, HIGH);
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
  pinMode(actmt, OUTPUT);
  digitalWrite(latch1, LOW);
  digitalWrite(actmt, LOW);
  //Serial.begin(9600);
}

void loop(){
  /*
   * 
   if (Serial.available()){
      data = Serial.parseInt();
      Serial.print(data);
      Serial.print(": ");
      Serial.println(data, BIN);
      moume(data);
  }
   *
   */
  moume(camin);
}
