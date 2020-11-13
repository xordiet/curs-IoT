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

//declarem la seqüència per array bidimensional sentit antihorari
int osap[4][4]={
  {1,0,0,1},
  {0,0,1,1},
  {0,1,1,0},
  {1,1,0,0}
};

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
  Serial.println("Introduiu un valor de fins a +-360");
}

void gir(float graus){ //declaro graus com a long i no int, ja que si passa de 32.767 al multiplicar per 512 peta
  bool sentit;
  //perquè giri xº necessitem j iteracions
  int j = graus * 512/360;
  int k = abs(j);
  int r = 512-k; // per completar el cicle la resta d'iteracions
  if(graus>0){
    sentit=true;
  } else {
    sentit=false;
  }
  
  Serial.print("gira ");
  Serial.print(graus);
  Serial.print("º, necessitem ");
  Serial.print(k);
  Serial.println(" iteracions");
  
  if(sentit == true){
    for(int i=0; i<k; i++){ 
      for(int i=0; i<4; i++){
        digitalWrite(IN1, paso[i][0]);
        digitalWrite(IN2, paso[i][1]);
        digitalWrite(IN3, paso[i][2]);
        digitalWrite(IN4, paso[i][3]);
        delay(demora);
     }
   }
  } else {
    for(int i=0; i<k; i++){ 
      for(int i=0; i<4; i++){
        digitalWrite(IN1, osap[i][0]);
        digitalWrite(IN2, osap[i][1]);
        digitalWrite(IN3, osap[i][2]);
        digitalWrite(IN4, osap[i][3]);
        delay(demora);
      }
    }
  }
  Serial.println("Introduiu un nou valor de fins a +-360");
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
      Serial.println("Error! Heu introduit un valor no vàlid, segur que és un número o diferent a 0?");
    } else if((data > 360)){
      Serial.println("Error! El número és major a 360, el valor màxim de graus");
    } else if((data < -360)){
      Serial.println("Error! El número és menor a -360, el valor mínim de graus");
    } else{
      gir(data);
    }
   }
}
