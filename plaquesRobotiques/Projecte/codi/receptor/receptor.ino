//definim els pins que usarem
int i1 = A0;
int i2 = A1;
int i3 = A2;
int i4 = A3;
int vt = A4;

//definim les variables que usarem
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val0 = 0;
int ear; // estat anterior del receptor per saber si canvia quan prems

void setup(){
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  pinMode(i4, INPUT);
  pinMode(vt, INPUT);
  Serial.begin(9600);
}

void loop(){
  val1 = digitalRead(i1);
  val2 = digitalRead(i2);
  val3 = digitalRead(i3);
  val4 = digitalRead(i4);
  val0 = digitalRead(vt);

  if(val0 != ear){
    if (val0 == HIGH){ //detecto flanc ascendent (premo)
      Serial.println("Presionat! ");
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
