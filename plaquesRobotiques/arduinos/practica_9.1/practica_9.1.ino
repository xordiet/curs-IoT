#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9 //Pin 9 para el reset del RC522
#define SS_PIN 10 //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creem l'objecte per al RC522

#define ENABLE 7
#define DIRA 6
#define DIRB 5

void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600); //Iniciem el port sèrie
  SPI.begin(); //Iniciem el Bus SPI
  mfrc522.PCD_Init(); // Iniciem el MFRC522
  Serial.println("Apropi targeta:");
}

byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuari[4]= {0xE9, 0x03, 0xAD, 0xA3} ; //código de l'usuari

void loop() {
  if ( mfrc522.PICC_IsNewCardPresent()){ // Si detecta una nova targeta
    if ( mfrc522.PICC_ReadCardSerial()){ // Si llegeix la tarja
      // Mostrem l'UID al port sèrie
      Serial.print(F("Card UID:"));
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] <0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i],HEX);
        ActualUID[i]=mfrc522.uid.uidByte[i];
      }
      Serial.print(" ");
      //Executem la comparació per veure si és la targeta garantida
      if(compareArray(ActualUID,Usuari)){
        Serial.println("Accés correcte...");
        Serial.println("...encèn fun!");
        encenfun();
      }else{
        Serial.println("Accés denegat...");
      }
      // Terminamos la lectura de la tarjeta tarjeta actual
      mfrc522.PICC_HaltA();
    }
  }
}

//Función per comparar dos vectors
boolean compareArray(byte array1[],byte array2[]){
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}

void encenfun(){
  Serial.println("inicia ventilador");
  digitalWrite(ENABLE,HIGH); // encen
  digitalWrite(DIRA,HIGH); //quina direcció
  digitalWrite(DIRB,LOW);
  delay(3000);
  digitalWrite(ENABLE,LOW);
}
