/*******************************************************
* Exercici 1. Motor continua + xip L293D. CANVI DE SENTIT I ATURADA
********************************************************/

#define ENABLE 3
#define DIRA 6
#define DIRB 5

void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  }
  
void antihorari(int temps) {
  digitalWrite(DIRA,HIGH); 
  digitalWrite(DIRB,LOW);
  delay(temps);
  }

void horari(int temps) {
  digitalWrite(DIRA,LOW); 
  digitalWrite(DIRB,HIGH);
  delay(temps);
  }
  
void loop() {
  digitalWrite(ENABLE,HIGH);
  //apunt per moure  5 segons en un sentit i 5 segons en altreanti
  horari(3000);
  antihorari(3000);
  digitalWrite(ENABLE,LOW); 
  //aturada de 1segon
  delay(1000);
  }
