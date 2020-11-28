#importa les llibreries
import time
import RPi.GPIO as GPIO
import adafruit_dht

#configura el sensor i el pin
GPIO.setmode(GPIO.BOARD)
sensor = adafruit_dht.DHT11(11)

temperature_c = dhtDevice.temperature

print (temperature_c)
