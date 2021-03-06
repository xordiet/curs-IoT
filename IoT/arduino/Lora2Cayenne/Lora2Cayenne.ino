/*
  Lora2Cayenne
  Enviant dades des de Lora a Cayenne
  v:1.0.0
*/

// Inclou les llibreries necessàries
#include <MKRWAN.h>
#include <CayenneLPP.h>

LoRaModem modem;
CayenneLPP lpp(51);

// Inclou l'AppEUI i l'AppKey, usant l'arxiu arduino_secrets.h per privacitat
#include "arduino_secrets.h"
String appEui = SECRET_APP_EUI;
String appKey = SECRET_APP_KEY;
String devAddr = DEVADDR;
String nwkSKey = NWKSKEY;
String appSKey = APP_SKEY;

// Codi d'inici, només s'executa un cop
void setup() {
  // Inicia el port sèrie per mostrar missatges a la consola
  Serial.begin(115200);
  // Defineix el LED_BUILTIN per mostrar missatges sense consola
  #define pinMode(LED_BUILTIN, OUTPUT);

  //while (!Serial);
  // Canviar segons la banda que usi el teu LoRa (ex. EU868, US915, AS923, ...)
  if (!modem.begin(EU868)) {
    Serial.println("Error a l'iniciar el mòdul");
    //Mostra l'error amb 3 blinks ràpids del LED_BUILTIN
    blinka(3, 100);
    while (1) {}
  } else {
    blinka(3, 500);;
  }
  Serial.print("Your module version is: ");
  Serial.println(modem.version());
  Serial.print("Your device EUI is: ");
  Serial.println(modem.deviceEUI());

  int connected = modem.joinABP(devAddr,nwkSKey,appSKey);
  //int connected = modem.joinOTAA(appEui, appKey);
  if (!connected) {
    Serial.println("Something went wrong; are you indoor? Move near a window and retry");
    //Mostra l'error amb 5 blinks ràpids del LED_BUILTIN
    blinka(5, 100);
    while (1) {}
  } else {
    Serial.println("Connexió exitosa");
    //Mostra que està funcionant amb 5 blinks d'1 segon del LED_BUILTIN
    blinka(5, 1000);
  }

  // Set poll interval to 180 secs.
  modem.minPollInterval(180);
  // NOTE: independently by this setting the modem will
  // not allow to send more than one message every 2 minutes,
  // this is enforced by firmware and can not be changed.
}

//Codi que s'executarà de manera repetitiva
void loop() {
  int err;
 
  lpp.reset();
  lpp.addTemperature(1, 11.5);
  modem.beginPacket();
  modem.write(lpp.getBuffer(), lpp.getSize());
  err = modem.endPacket(true);
  if (err > 0) {
    Serial.println("Message sent correctly!");
    //Mostra que està funcionant amb 15 blinks lents del LED_BUILTIN
    blinka(15, 500);
  } else {
    Serial.println("Error sending message :(");
    Serial.println("(you may send a limited amount of messages per minute, depending on the signal strength");
    Serial.println("it may vary from 1 message every couple of seconds to 1 message every minute)");
    //Mostra l'error amb 30 blinks ràpids del LED_BUILTIN
    blinka(30, 100);
  }
  delay(1000);
  if (!modem.available()) {
    Serial.println("No downlink message received at this time.");
  }
  else {
    String rcv;
    rcv.reserve(64);
    while (modem.available()) {
      rcv += (char)modem.read();
    }
    Serial.print("Received: " + rcv + " - ");
    for (unsigned int i = 0; i < rcv.length(); i++) {
      Serial.print(rcv[i] >> 4, HEX);
      Serial.print(rcv[i] & 0xF, HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println("pausa de 10 minuts");
  for (int i=0; i<10; i++) { //pausa d'un minut
    Serial.print(i);
    delay(1000*60);
    blinka(1, 1000);
  } 
}

void blinka (int cops, int dely){
  for (int i=1; i<=cops; i++) {          
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(dely);                       
      digitalWrite(LED_BUILTIN, LOW);    
      delay(dely);                       
  }
}
