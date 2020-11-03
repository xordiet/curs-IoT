#include <LiquidCrystal.h>

//Crea l'objete LCD amb els núms assignats (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int PIRPin= 7;

void setup(){
  pinMode(PIRPin, INPUT);
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
  int value= digitalRead(PIRPin);
  if (value == HIGH){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Intrus!!! 0_0");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tot O.K. :)");
  }
  delay(1000);
}
