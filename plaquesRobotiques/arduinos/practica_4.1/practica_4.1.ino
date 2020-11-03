#include <LiquidCrystal.h>

//Crea l'objete LCD amb els números asignats (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  Serial.begin(9600);
  // Inicialitzo l'LCD amb el nombre de fileres i columnes
  lcd.begin(16, 2);
  // Escric el missatge inicial.
  lcd.setCursor(0, 0);
  lcd.print("Hola Mon!");
  lcd.setCursor(0, 1);
  lcd.print("Hello World!");
  delay(1000);
}

void loop(){
  //posicionem el cursor al punt que ens interessa (columna línea)
}
