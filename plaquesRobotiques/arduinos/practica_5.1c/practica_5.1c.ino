#include <Keypad.h>
#include <LiquidCrystal.h>

//Crea l'objete LCD amb els núms assignats (rs, e, d4, d5, d6, d7)
/*
 * 
Pin 14 is Analog in 0
Pin 15 is Analog in 1
Pin 16 is Analog in 2
Pin 17 is Analog in 3
Pin 18 is Analog in 4
Pin 19 is Analog in 5
 */
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

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

//inicialitza una instància de la classe NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int r_pin = 3;
int g_pin = 5;
int b_pin = 6;

//inicialitzo variables
int compta = 0;
String codi = "";

void setup() {
  //Serial.begin(9600);
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  // Inicialitzo l'LCD amb el nombre de fileres i columnes
  lcd.begin(16, 2);
  // Escric el missatge inicial.
  lcd.setCursor(0, 0);
  lcd.print("Hola Mon!");
  lcd.setCursor(0, 1);
  lcd.print("Hello World!");
  delay(1000);
  lcd.clear();
  lcd.print("Premeu codi HEX:");
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey){
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
  analogWrite(r_pin, r);
  analogWrite(g_pin, g);
  analogWrite(b_pin, b);
  lcd.setCursor(0, 1);
  lcd.print(codi);
}
