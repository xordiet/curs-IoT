import serial
import time
import cayenne.client
import logging
import sys

#info d'autenticacio de cayenne
MQTT_USERNAME = "bf9f5d20-0d4c-11eb-8779-7d56e82df461"
MQTT_PASSWORD  = "6c49c56c1a87e43b06c0c93eb63cd10101099fab"
MQTT_CLIENT_ID = "43e22db0-0f87-11eb-883c-638d8ce4c23d"

arduino = serial.Serial(
	port = "/dev/ttyACM0",
	baudrate = 9600,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=1)

print("Inici lectura!")

client = cayenne.client.CayenneMQTTClient()
#client.on_message = on_message
client.begin(MQTT_USERNAME, MQTT_PASSWORD, MQTT_CLIENT_ID)

while True:
	try:
		data = str(arduino.readline())
		d = data[2:-1]
		c = d.split(";")
		#print(len(c))
		if(len(c) > 1):
			print (c)
			client.loop()
			client.virtualWrite(0,c[0])
			client.virtualWrite(1,c[1])
			client.virtualWrite(2,c[2])
	#except KeyboardInterrupt:
		#break
	except:
		pass

arduino.close()
sys.exit()
