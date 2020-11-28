#include <dht.h>

dht DHT;

#define DHT11_PIN 7
int id=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("id: ");
  Serial.println(id);
  Serial.print("Temperatura = ");
  Serial.println(DHT.temperature);
  Serial.print("Humitat = ");
  Serial.println(DHT.humidity);
  id++;
  delay(3000);
}
