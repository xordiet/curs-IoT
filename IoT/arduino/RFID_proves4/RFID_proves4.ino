#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
#define LED_G 1 //Pin per al led verd
#define LED_R 0 //Pin per al led vermell
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

//Crea l'objete LCD amb els números asignats (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(8, 6, 5, 4, 3, 2);

void setup() {
  //Serial.begin(9600); //Iniciamos la comunicación  serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos  el MFRC522
  Serial.println("Lectura del UID");
   // Inicialitzo l'LCD amb el nombre de fileres i columnes
  lcd.begin(16, 2);
  // Escric el missatge inicial.
  lcd.print("Lector RFID");
  lcd.setCursor(0, 1);
  lcd.print("v. 1.0.0");
  //iniciem els leds
  pinMode(LED_G , OUTPUT);
  pinMode(LED_R , OUTPUT);
  digitalWrite(LED_G , LOW);
  digitalWrite(LED_R , LOW);
  delay(3000);
}

byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuari[4]= {0xE9, 0x03, 0xAD, 0xA3} ;
void loop() {
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print("Card UID:");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Targeta ID: ");
                  lcd.setCursor(0,1);
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          //Serial.print(mfrc522.uid.uidByte[i]);
                          Serial.print(mfrc522.uid.uidByte[i], HEX);
                          lcd.print(mfrc522.uid.uidByte[i], HEX);
                          ActualUID[i]=mfrc522.uid.uidByte[i];   
                  }
                  Serial.println();

                  //revisem l'usuari
                  if(compareArray(ActualUID,Usuari))
                  {
                    Serial.print("OK");
                    digitalWrite(LED_G , HIGH);
                    delay(2000);
                    digitalWrite(LED_G, LOW);
                    Serial.println();
                  }
                  else
                  {
                    //encenem el led vermell
                    digitalWrite(LED_R, HIGH);
                    Serial.print("KO");
                    delay(2000);
                    digitalWrite(LED_R, LOW);
                    Serial.println();
                  }
                  
                  // Terminamos la lectura de la tarjeta  actual
                  mfrc522.PICC_HaltA();         
            }
            //Serial.print("id: "+ActualUID[4]);      
  } 
}

boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
