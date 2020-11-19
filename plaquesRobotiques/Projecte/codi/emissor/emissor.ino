//definim els pins que usarem
int o1 = 2;
int o2 = 3;
int o3 = 4;
int o4 = 5;


void premboto(int bt){
  digitalWrite(bt, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(bt, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  }

void setup(){
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
  pinMode(o3, OUTPUT);
  pinMode(o4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(o1, HIGH);
  digitalWrite(o2, HIGH);
  digitalWrite(o3, HIGH);
  digitalWrite(o4, HIGH);
  Serial.begin(9600);
}

void loop(){
   /*if (Serial.available() > 0){
      int data = Serial.parseInt();
      Serial.println("rebut!");
      Serial.println(data);
      switch(data){
        case 1:
          premboto(o1);
          break;
        case 2:
          premboto(o2);
          break;
        case 3:
          premboto(o3);
          break;
        case 4:
          premboto(o4);
          break;
        default:
          Serial.println("Valor no vàlid");
          break;
      }
        
      }*/
  premboto(o2);
  delay(2000);
}
