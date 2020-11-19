//definim els pins que usarem
int i1 = A0;
int i2 = A1;
int i3 = A2;
int i4 = A3;
int vt = A4;
int val1;
int val2;
int val3;
int val4;
int val0;
int eab; // estat anterior del botó per saber si canvia quan prems

//definim les variables que usarem

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

  Serial.print(val1);
  Serial.print(" ");
  Serial.print(val2);
  Serial.print(" ");
  Serial.print(val3);
  Serial.print(" ");
  Serial.print(val4);
  Serial.print(" ");
  Serial.println(val0);

  /*
  if(val2 != eab){
    //if (val0 == LOW){ //detecto flanc descendent (deixo anar)
    if (val2 == LOW){ //detecto flanc ascendent (premo)
      Serial.print("Presionat! ");
      Serial.print(val1);
  Serial.print(" ");
  Serial.print(val2);
  Serial.print(" ");
  Serial.print(val3);
  Serial.print(" ");
  Serial.print(val4);
  Serial.print(" ");
  Serial.println(val0);
    }
  }
  eab = val2; //actualitzo estat per al proper loop
  */
}
