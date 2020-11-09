
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9  //configurable
#define SS_PIN 10  //configuragle
MFRC522 mfrc522(SS_PIN, RST_PIN); // crea la instancia MFRC522
void setup() {
Serial.begin(9600);   // inicia comunicación serie con el pc
SPI.begin();          // inicia el bus SPI
mfrc522.PCD_Init();   // Inicia tarjeta MFRC522
Serial.println(F("Ingrese Tarjeta para Escribir Dato Personal"));
}
void loop() {
// Prepare key-Inicialmente chip a FFFFFFFFFFFFh de fabrica
MFRC522::MIFARE_Key key;
for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF; //hasta el bloque6
if ( ! mfrc522.PICC_IsNewCardPresent()) {  //detecta nueva tarjeta
return;
}

if ( ! mfrc522.PICC_ReadCardSerial()) return;   //selecciona la tarjeta
Serial.print(F("Num. de Serie unico:"));       //Dump UID
for (byte i = 0; i < mfrc522.uid.size; i++) {
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
}
Serial.print(F(" PICC type: "));           // Dump PICC type
MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
Serial.println(mfrc522.PICC_GetTypeName(piccType));
byte buffer[34];
byte block;
MFRC522::StatusCode status;
byte len;
Serial.setTimeout(20000L) ; // espera antes de comunicacion serie
Serial.println(F("Escriba Dato, al final incluya #")); //informa
len=Serial.readBytesUntil('#', (char *) buffer, 20) ; //lectura serie hasta#
for (byte i = len; i < 20; i++) buffer[i] = ' '; // almohadilla con espacios
block = 6; //Especifica en que bloque escribira ___------___-----___
//Serial.println(F("Authenticating using key A..."));
status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
if (status != MFRC522::STATUS_OK) {
Serial.print(F("PCD_Authenticate() failed: "));
Serial.println(mfrc522.GetStatusCodeName(status));
return;
}

status = mfrc522.MIFARE_Write(block, buffer, 16); //escribe el bloque
if (status != MFRC522::STATUS_OK) {
Serial.print(F("MIFARE_Write() failed: "));
Serial.println(mfrc522.GetStatusCodeName(status));
return;
}
else Serial.println(F("MIFARE_Write() Escritura Realizada Corectamente: "));
block = 5;
//Serial.println(F("Authenticating using key A..."));
status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
if (status != MFRC522::STATUS_OK) {
Serial.print(F("PCD_Authenticate() failed: "));
Serial.println(mfrc522.GetStatusCodeName(status));
return;
}
// Write block
status = mfrc522.MIFARE_Write(block, &buffer[16], 16);
if (status != MFRC522::STATUS_OK) {
Serial.print(F("MIFARE_Write() failed: "));
Serial.println(mfrc522.GetStatusCodeName(status));
return;
}
else Serial.println(F("MIFARE_Write() Escritura Realizada Corectamente: "));
Serial.println(" ");
mfrc522.PICC_HaltA(); // Halt PICC
mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
}
