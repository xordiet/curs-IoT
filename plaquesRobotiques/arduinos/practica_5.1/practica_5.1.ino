#include <Keypad.h>
#include <LiquidCrystal.h>

//Crea l'objete LCD amb els núms assignats (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(1, 0, 5, 4, 3, 2);

//Crea les tuples del teclat
const byte ROWS = 4; //quatre fileres
const byte COLS = 4; //quatre columnes
//define la disposició dels botons
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connecta els pins de les fileres
byte colPins[COLS] = {9, 8, 7, 6}; //connecta els pins de les columnes

String psw = "1714"; //codi que donarà accés
String codi = ""; //guardarà el codi que vagi escrivint
int cont = 0; //per saber si el codi està buit

//inicialitza una instància de la classe NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Inicialitzo l'LCD amb el nombre de fileres i columnes
  lcd.begin(16, 2);
  // Escric el missatge inicial.
  lcd.setCursor(0, 0);
  lcd.print("Hola Mon!");
  lcd.setCursor(0, 1);
  lcd.print("Hello World!");
  delay(1000);
  lcd.clear();
  lcd.print("Premeu codi i #:");
  lcd.setCursor(0, 1);
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey){
    //si apreto # valida el codi i mostra-ho
    if (customKey == '#'){ 
      lcd.clear();
      lcd.print("Premeu codi i #:");
      lcd.setCursor(0, 1);
      if(codi==psw){
        lcd.print("Codi O.K.");
      } else {
        lcd.print("Codi erroni!");
      }
      cont = 0;
      codi = "";
    //si premo qualsevol altra tecla emmagatzema-ho al string i mostra * en pantalla
    } else {
      codi = codi+customKey;
      if(cont==0){
        lcd.clear();
        lcd.print("Premeu codi i #:");
        lcd.setCursor(0, 1);
        lcd.print('*');
        cont = 1;
      } else {
        lcd.print('*');
      }
    }    
  }
}
