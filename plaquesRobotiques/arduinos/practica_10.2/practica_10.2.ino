/*******************************************************
* Exercici 2. Motor continua + xip L293D. CANVI DE VELOCITAT + SENTIT
********************************************************/

#define ENABLE 3
#define DIRA 6
#define DIRB 5

void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  }
  
void loop() {
  digitalWrite(DIRA,HIGH); 
  digitalWrite(DIRB,LOW);
  analogWrite(ENABLE, 100);
  delay(3000);
  digitalWrite(DIRA,LOW); 
  digitalWrite(DIRB,HIGH);
  analogWrite(ENABLE, 240);
  delay(3000);
  }
