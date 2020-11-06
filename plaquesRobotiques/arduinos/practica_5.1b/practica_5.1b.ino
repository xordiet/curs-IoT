#include <Keypad.h>

//Crea les tuples del teclat
const byte ROWS = 4; //quatre fileres
const byte COLS = 4; //quatre columnes
//define la disposició dels botons
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'F', '0', 'E', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connecta els pins de les fileres
byte colPins[COLS] = {9, 8, 7, 4}; //connecta els pins de les columnes

int r_pin = 3;
int g_pin = 5;
int b_pin = 6;

//inicialitza una instància de la classe NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//inicialitzo variables
int compta = 0;
String codi = "";

void setup() {
  Serial.begin(9600);
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey){
    //mostra-ho al port sèrie
    Serial.print(customKey);
    codi = codi+customKey;
    compta++;
    //si té sis caràcters
    if(compta == 6){
      validaCodi(codi);
      compta=0;
      codi="";
    }    
  }
}

void validaCodi (String codi){
  const char* cadena = codi.c_str();
  int r, g, b;
  sscanf(cadena, "%02x%02x%02x", &r, &g, &b);
  Serial.println("");
  Serial.print("codi introduït: ");
  Serial.print(codi);
  Serial.println("");
  Serial.print(r);
  analogWrite(r_pin, r);
  Serial.print(" ");
  Serial.print(g);
  analogWrite(g_pin, g);
  Serial.print(" ");
  Serial.print(b);
  analogWrite(b_pin, b);
  Serial.println("");
  
}
