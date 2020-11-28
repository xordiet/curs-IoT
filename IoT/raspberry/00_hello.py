#importem les llibreries necessaries
import RPi.GPIO as GPIO
import time

#establim el pin que usarem per encendre/apagar
pn = 12

#configurem el GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(pn,GPIO.OUT,initial=GPIO.LOW)

#establim el temps de refresc
tm = 0.2

#bucle
while True:
	print "LED on"
	GPIO.output(pn,GPIO.HIGH)
	time.sleep(tm)
	print "LED off"
	GPIO.output(pn,GPIO.LOW)
	time.sleep(tm)
