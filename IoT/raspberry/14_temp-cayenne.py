import RPi.GPIO as GPIO
import dht11
import cayenne.client
import time
import logging
import sys

# initialitza el GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.cleanup()

#informació d'Autenticació de Cayenne
MQTT_USERNAME = "xxx"
MQTT_PASSWORD = "xxx"
MQTT_CLIENT_ID = "xxx"

# llegir la data llegint el pin 11
instance = dht11.DHT11(pin = 11)
result = instance.read()

def on_message(message):
	print("missatge rebut: " + str(message))

#connexió
client = cayenne.client.CayenneMQTTClient()
client.on_message = on_message
client.begin(MQTT_USERNAME, MQTT_PASSWORD, MQTT_CLIENT_ID, port=8883)

while True:
	try:
		client.loop()
		#print("temperatura: "+str(result.temperature))
		client.celsiusWrite(0, result.temperature)
		#print("humitat: "+str(result.humidity))
		client.virtualWrite(1, result.humidity)
		timestamp = time.time()
		time.sleep(60)

	except KeyboardInterrupt:
		break

sys.exit()
