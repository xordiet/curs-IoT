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
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

String codi = "";

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
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey){
    codi = codi+customKey;
    lcd.print(customKey);
  }
}
