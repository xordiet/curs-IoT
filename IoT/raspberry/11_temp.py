#importa les llibreries
'''import RPi.GPIO as GPIO
import time
'''
import Adafruit_DHT as dht

'''
#inicialitza GPIO
GPIO.setwarnings(True)
GPIO.setmode(GPIO.BOARD)
'''

#llegeix dades
sensor = dht.DHT11
pn=11
tm = 3

ht, tp = dht.read_retry(sensor, pn)
if ht is not None and tp is not None:
	print ("Hola")
else:
	print ("Error")

'''
while True:
	ht, tp = dht.read_retry(sensor, pn)
	print ("resultats = "+tp)
	time.sleep(tm)
'''
