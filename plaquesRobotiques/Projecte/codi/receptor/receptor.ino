//definim els pins que usarem
int i1 = A0;
int i2 = A1;
int i3 = A2;
int i4 = A3;
int vt = A4;

//definim les variables que usarem
int val0 = 0; //estat del valor del pin0 per detectar canvis d'estat
int ear; // estat anterior del receptor per saber si canvia quan prems
int estb[4]; //els estats de base
int esta[4]; //els estats actuals
int canviara;


void setup(){
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  pinMode(i4, INPUT);
  pinMode(vt, INPUT);
  Serial.begin(9600);
}

//Funció per comparar dos vectors
boolean comparaArrays(int array1[],int array2[]){
  if(array1[0] != array2[0]){
    canviara=1;
    return(true);
  }
  if(array1[1] != array2[1]){
    canviara=2;
    return(true);
  }
  if(array1[2] != array2[2]){
    canviara=3;
    return(true);
  }
  if(array1[3] != array2[3]){
    canviara=4;
    return(true);
  }
  return(false);
}

void revisa(){
  delay(20);
  esta[0] = digitalRead(i1);
  esta[1] = digitalRead(i2);
  esta[2] = digitalRead(i3);
  esta[3] = digitalRead(i4);
  Serial.println("Presionat! ");
  //imprimeix el valor emmagatzemat
  //Serial.print("Valors en memòria:\t\t");
  for(int i=0; i<4; i++){
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(estb[i]);
    Serial.print(";\t");
  }
  Serial.println("");
  //imprimeix els valors actuals
  //Serial.print("vt: "+String(val0)+";\t";
  Serial.print("1: "+String(esta[0])+";\t");
  Serial.print("2: "+String(esta[1])+";\t");
  Serial.print("3: "+String(esta[2])+";\t");
  Serial.print("4: "+String(esta[3])+";");
  Serial.println("");
  boolean canvis = comparaArrays(esta,estb);
  if(canvis==true)Serial.println("canvia: "+String(canviara));
  //actualitzo l'estat base
  for (int i=0; i<4; i++){
    estb[i]=esta[i];
  }
}

void loop(){
  val0 = digitalRead(vt);

  if(val0 != ear){
    if (val0 == HIGH){ //detecto flanc ascendent (premo)
      revisa();      
    }
  }
  ear = val0; //actualitzo estbat per al proper loop
}
