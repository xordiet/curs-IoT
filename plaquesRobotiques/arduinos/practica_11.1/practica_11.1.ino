/*********************************************************
* Exercici 1. Pasar a millis() un programa fet amb delay *
*********************************************************/
//defineixo els pins a usar
#define ENABLE 3
#define DIRA 6
#define DIRB 5

//defineixo variables a usar
unsigned long tempsAnterior = millis();

void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}
  
void loop() {
  //Moure  3 segons en un sentit i 3 segons en altreanti i després una pausa d'un segon
  unsigned long tempsAra=millis();
  digitalWrite(ENABLE,HIGH);
  if(tempsAra - tempsAnterior < 3000){
    digitalWrite(DIRA,HIGH); 
    digitalWrite(DIRB,LOW);
  } else if(tempsAra - tempsAnterior < 6000){
    digitalWrite(DIRA,LOW); 
    digitalWrite(DIRB,HIGH);
  } else if((tempsAra - tempsAnterior > 6000) and (tempsAra - tempsAnterior < 7000)){
    digitalWrite(ENABLE,LOW); 
  } else if(tempsAra - tempsAnterior > 7000){
    Serial.println(tempsAnterior);
    tempsAnterior = tempsAra;
    Serial.println(tempsAnterior);
  }
}
