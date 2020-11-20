//definim els pins que usarem
int latch1 = 8;      // ST_CP (12) al 74HC595 front
int clock1 = 13;     // SH_CP (11) al 74HC595 front
int dataP1 = 12;     // DS    (14) al 74HC595 front
int actmt = 9; // pin que activara o no els motors
int boto = 7;

//  segon 74HC595 
int latch2 = 3; //ST_CP
int clock2 = 4; //SH_CP
int dataP2 = 2; //DS

//receptor radiofreqüència
int i1 = A0;
int i2 = A1;
int i3 = A2;
int i4 = A3;
int vt = A4;

//definim les variables que usarem
int veloc = 255; // velocitat del vehicle
int mode = 0; // variables que emmagatzemaran en quin mode de conducció estem
int conducc[10] = {
  0,   //mode 0 apagat
  170, //mode 1 tot endavant
  85,  //mode 2 tot enrera
  153, //mode 3 gira dreta
  102, //mode 4 gira esquerra
  0, //mode 5
  0, //mode 6
  0, //mode 7
  0, //mode 8
  0  //mode 9
  };
int camin = 0; // variable que emmagatzemarà en quina direcció aniran els motors
/*
-------------------------------------------------------------------
| direcció |        davanters      |        darrera        | suma |
-------------------------------------------------------------------
|          |    de     |     dd    |    re     |     rd    |      |
-------------------------------------------------------------------
|          | dea | deb | dda | ddb | rea | reb | rda | rdb |      |
-------------------------------------------------------------------
| endavant |  1  |  0  |  1  |  0  |  1  |  0  |  1  |  0  |  170 |
-------------------------------------------------------------------
| gir dret |  1  |  0  |  0  |  1  |  1  |  0  |  0  |  1  |  153 |
-------------------------------------------------------------------
| gir esq. |  0  |  1  |  1  |  0  |  0  |  1  |  1  |  0  |  102 |
-------------------------------------------------------------------
| enrrere  |  0  |  1  |  0  |  1  |  0  |  1  |  0  |  1  |   85 |
-------------------------------------------------------------------
| a sumar  | 128 |  64 |  32 |  16 |  8  |  4  |  2  |  1  |      |
-------------------------------------------------------------------
*/
byte data = 0; //dada que rebrem del port sèrie
int eab; // estat anterior del botó de la breadboard per saber si canvia quan prems

// byte que guarda la combinació per al display del mode conducció
byte d7digits[10] = { B11111100,  // = 0
                      B01100000,  // = 1
                      B11011010,  // = 2
                      B11110010,  // = 3
                      B01100110,  // = 4
                      B10110110,  // = 5
                      B10111110,  // = 6
                      B11100000,  // = 7
                      B11111110,  // = 8
                      B11110110   // = 9
                    };

//varialbles del receptor de radiofreqüència
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val0 = 0;
int ear; // estat anterior del receptor per saber si canvia quan prems
int rec[4];

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

void escriu7digis(byte digit) {
  Serial.print("escriu: ");
  Serial.println(digit);
  digitalWrite(latch2, LOW);
  shiftOut(dataP2, clock2, LSBFIRST, d7digits[digit]); 
  digitalWrite(latch2, HIGH);
}

void modeSerie(){
  //mou segons el que li passi per port sèrie
  if (Serial.available() > 0){
      data = Serial.parseInt();
      Serial.println("rebut!");
      Serial.print(data);
      Serial.print(": ");
      Serial.println(data, BIN);
      if (data==0){
        aturam();
      } else {
        //aturam();
        //delay(10);
        moume(data);
      }
  }
}

void modeJoys(){
  val1 = digitalRead(i1);
  val2 = digitalRead(i2);
  val3 = digitalRead(i3);
  val4 = digitalRead(i4);
  val0 = digitalRead(vt);

  if(val0 != ear){
    if (val0 == LOW){ //detecto flanc ascendent (premo)
      /*for(int i=0;i<4;i++){
        Serial.print(rec[i]);
        Serial.print(" ");
      }*/
      Serial.println("");
      Serial.println("Joystick! ");
      Serial.print("vt: ");
      Serial.print(val0);
      Serial.print("\t1: ");
      Serial.print(val1);
      Serial.print("\t2: ");
      Serial.print(val2);
      Serial.print("\t3: ");
      Serial.print(val3);
      Serial.print("\t4: ");
      Serial.println(val4);
      
    }
  }
  ear = val0; //actualitzo estat per al proper loop
}

void canviaMode(int mode){
  switch(mode){
    case 1:
    case 2:
    case 3:
    case 4:
      moume(conducc[mode]);
      break;
    case 5:
      aturam();
      break;
    case 6:
      aturam();
      break;
    default:
      break;
  }
}
void revisaMode(int mode){
  switch(mode){
    case 1:
    case 2:
    case 3:
    case 4:
      break;
    case 5:
      modeJoys();      
      break;
    case 6:
      modeSerie();
      break;
    default:
      break;
  }
}

void setup(){
  pinMode(latch1, OUTPUT);
  pinMode(clock1, OUTPUT);
  pinMode(dataP1, OUTPUT);
  pinMode(latch2, OUTPUT);
  pinMode(clock2, OUTPUT);
  pinMode(dataP2, OUTPUT);
  pinMode(actmt, OUTPUT);
  pinMode(boto, INPUT_PULLUP);
  eab = digitalRead(boto);
  digitalWrite(latch1, LOW);
  digitalWrite(actmt, LOW);
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  pinMode(i4, INPUT);
  pinMode(vt, INPUT);
  rec[0]=digitalRead(i1);
  rec[1]=digitalRead(i2);
  rec[2]=digitalRead(i3);
  rec[3]=digitalRead(i4);
  Serial.begin(9600);
}

void loop(){
  //mou segons el definit al mode conducció
  int sensorBot = digitalRead(boto);
  //Serial.println(sensorBot);
  if(sensorBot != eab){
    if (sensorBot == LOW){ //detecto flanc descendent (deixo anar)
      Serial.print("Presionat! ");
      if (mode==9){
        mode = 0;
      } else {
        mode++;
      }
      Serial.println(mode);
      escriu7digis(mode);
      canviaMode(mode);
    }
  }
  revisaMode(mode);
  eab = sensorBot; //actualitzo estat per al proper loop
}
