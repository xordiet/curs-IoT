#define ENABLE 3
#define DIRA 6
#define DIRB 5
#define ENABLI 11
#define DISA 10
#define DISB 9

void setup() {
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(ENABLI,OUTPUT);
  pinMode(DISA,OUTPUT);
  pinMode(DISB,OUTPUT);
  }
  
void loop() {
  digitalWrite(ENABLE, HIGH);
  digitalWrite(DIRA,HIGH); 
  digitalWrite(DIRB,LOW);
  digitalWrite(ENABLI, HIGH);
  digitalWrite(DISA,HIGH); 
  digitalWrite(DISB,LOW);
  delay(3000);
  digitalWrite(ENABLE, HIGH);
  digitalWrite(DIRA,LOW); 
  digitalWrite(DIRB,HIGH);
  digitalWrite(ENABLI, HIGH);
  digitalWrite(DISA,LOW); 
  digitalWrite(DISB,HIGH);
  delay(3000);
  }
