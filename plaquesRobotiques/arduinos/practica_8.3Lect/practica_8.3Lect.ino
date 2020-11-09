
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9 // Configurable
#define SS_PIN 10 // Configurable
MFRC522 mfrc522(SS_PIN, RST_PIN); // Crea MFRC522 instancia.
MFRC522::MIFARE_Key key;
void setup() {
Serial.begin(9600);   // Initializa serial communications con PC
while (!Serial);     // parar si el puerto  está abierto
SPI.begin();        // Inicia SPI bus
mfrc522.PCD_Init(); // Inicia MFRC522 card
// utiliza FFFFFFFFFFFFh que son los datos en chip de fábrica
for (byte i = 0; i < 6; i++) {  //solo el bloque6
key.keyByte[i] = 0xFF;
}
Serial.println(F("Ingrese Tarjeta"));
}
void loop() {

if ( ! mfrc522.PICC_IsNewCardPresent())  //mira si hay nueva tarjeta
return;

if ( ! mfrc522.PICC_ReadCardSerial())  //selecciona la nueva tarjeta
return;
byte sector = 1;
byte blockAddr = 6; //Lee solo del bloque6 sus 16bytes
byte dataBlock[] = {
0x01, 0x02, 0x03, 0x04, // 1, 2, 3, 4,
0x05, 0x06, 0x07, 0x08, // 5, 6, 7, 8,
0x08, 0x09, 0xff, 0x0b, // 9, 10, 255, 12,
0x0c, 0x0d, 0x0e, 0x0f // 13, 14, 15, 16
};
byte trailerBlock = 7;
MFRC522::StatusCode status;
byte buffer[18];
byte size = sizeof(buffer);
Serial.println(F("Datos actuales en el sector:"));
mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector);
Serial.println();

Serial.print(F("Cargando dato del bloque ")); Serial.print(blockAddr);
Serial.println(F(" ..."));
status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);
if (status != MFRC522::STATUS_OK) {
Serial.print(F("MIFARE_Read() failed: "));
Serial.println(mfrc522.GetStatusCodeName(status));
}
Serial.print(F("Dato en el bloque ")); Serial.print(blockAddr); Serial.println(F(":"));
dump_byte_array(buffer, 16); Serial.println();
Serial.println();
}
/**
* Rutina que envia el valor hex al puerto serie.
*/
void dump_byte_array(byte *buffer, byte bufferSize) {
for (byte i = 0; i < bufferSize; i++) {
// Serial.print(buffer[i] < 0x10 ? " 0" : " ");
// Serial.print(buffer[i], HEX);
Serial.write(buffer[i]);
}
}
