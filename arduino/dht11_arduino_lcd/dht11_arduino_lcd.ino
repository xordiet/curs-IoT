#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;
//Crea l'objete LCD amb els números asignats (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHT11_PIN 7
int id=0;

void setup(){
  Serial.begin(9600);
  // Inicialitzo l'LCD amb el nombre de fileres i columnes
  lcd.begin(16, 2);
  // Escric el missatge inicial.
  lcd.print("Sensor DHT11");
  lcd.setCursor(0, 1);
  lcd.print("v. 1.0.0");
  delay(3000);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  //Serial.print("id: ");
  Serial.print(id);
  Serial.print(";");
  //Serial.print("Temperatura: ");
  Serial.print(DHT.temperature);
  Serial.print(";");
  //Serial.print("Humitat: ");
  Serial.print(DHT.humidity);
  Serial.print(";");
  //i ara ho imprimim a l'LCD
  lcd.clear();
  //posicionem el cursor al punt que ens interessa (columna línea)
  lcd.setCursor(0, 0);
  //i escrivim
  lcd.setCursor(0,0);
  lcd.print("id: ");
  lcd.print(id);
  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.print(DHT.temperature);
  lcd.print("/H:");
  lcd.print(DHT.humidity);
  id++;
  delay(3000);
}
