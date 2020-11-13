//defineixo els pins a usar
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 15; //la pausa entre passos, no pot ser inferior a 10 ms

//declarem la seqüència per array bidimensional
int paso[4][4]={
  {1,1,0,0},
  {0,1,1,0},
  {0,0,1,1},
  {1,0,0,1}
};

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
  Serial.println("Introduiu un número de graus pel gir");
}

void gir(float graus){ //declaro graus com a long i no int, ja que si passa de 32.767 al multiplicar per 512 peta
  //perquè giri xº necessitem j iteracions
  int j = graus * 512/360;
  int r = 512-j; // per completar el cicle la resta d'iteracions
  
  Serial.print("gira ");
  Serial.print(graus);
  Serial.print("º, necessitem ");
  Serial.print(j);
  Serial.println(" iteracions");
  
  for(int i=0; i<j; i++){ 
    for(int i=0; i<4; i++){
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  Serial.println("Introduiu un nou valor");
}
  
void loop() {
  /**
   * un cicle 8 passos
   * un gir requereix 8 cicles
   * un gir requereix 64 voltes (reducció 1:64)
   * 4*8*64=2048 pasos per a una sola revolució
   * 512*4=2048 passos el for serà de 512
   */
   if (Serial.available()){
    int data = Serial.parseInt();
    if(data==0){
      Serial.println("Error! Heu introduit un valor no vàlid, segur que és un número?");
    } else {
      gir(data);
    }
   }
}
