//defineixo els pins a usar
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 20; //la pausa entre passos, no pot ser inferior a 10 ms

//declarem la seqüència per array bidimensional
int paso[4][4]={
  {1,0,0,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,0,0,1}
};

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
}
  
void loop() {
  /**
   * un cicle 4 passos
   * un gir requereix 8 cicles
   * un gir requereix 64 voltes (reducció 1:64)
   * 4*8*64=2048 pasos per a una sola revolució
   * 512*4=2048 passos el for serà de 512
   */
  for(int i=0; i<512; i++){ 
    for(int i=0; i<4; i++){
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  //aturem tot 5 segons abans de repetir la volta
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(5000);
}
