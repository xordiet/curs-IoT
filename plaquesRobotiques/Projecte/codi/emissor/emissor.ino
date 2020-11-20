//definim els pins que usarem per l'emissor
int o1 = 2;
int o2 = 3;
int o3 = 4;
int o4 = 5;
int eaj = 0; // estat anterior del joystick per saber si canvia quan prems

//definim els pins que usarem pel joystick
const int SW_pin = 1; // digital pin connected to switch output
const int X_pin = A1; // analog pin connected to X output
const int Y_pin = A2; // analog pin connected to Y output

//variables que guarden els valors del joystick
int lx;
int ly;
int estat;

void premboto(int bt){
  digitalWrite(bt, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(10);
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
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop(){
  lx=analogRead(X_pin);
  ly=analogRead(Y_pin);
  
  /*
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  */

  /*
   * 
   * Si activo el pin 1 de l'emissor canvia l'estat del pin 3 del receptor
   * Si activo el pin 2 de l'emissor canvia l'estat del pin 4 del receptor
   * Si activo el pin 3 de l'emissor canvia l'estat del pin 2 del receptor
   * Si activo el pin 4 de l'emissor canvia l'estat del pin 1 del receptor
   * 
   */
  if((lx>250 and lx<750) and ly < 250){ // endavant
    estat = 1;  
  } else if(lx > 750 and (ly>250 and ly<750)){ // dreta
    estat = 2;  
  } else if((lx>250 and lx<750) and ly > 750){ // enrera
    estat = 3;  
  } else if(lx < 250 and (ly>250 and ly<750)){ // esquerra
    estat = 4;  
  } else {
    estat = 0;
  }

  if(estat != eaj){
    Serial.print("estat anterior: ");
    Serial.print(eaj);
    Serial.print(" estat actual: ");
    Serial.println(estat);
    switch(estat){
      case 1:
        premboto(o4);
        break;
      case 2:
        premboto(o3);
        break;
      case 3:
        premboto(o1);
        break;
      case 4:
        premboto(o2);
        break;
      default:
        switch(eaj){
          case 1:
            premboto(o4);
            break;
          case 2:
            premboto(o3);
            break;
          case 3:
            premboto(o1);
            break;
          case 4:
            premboto(o2);
            break;
          default:
            break;
        }
        break;
    }
    eaj=estat;
  }
  //delay(2000);
}
