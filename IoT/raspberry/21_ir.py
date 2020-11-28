import RPi.GPIO as GPIO
import time
import os

pin = 12

# initialize GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(pin,GPIO.IN)

while True:
	i=GPIO.input(pin)
	print(i)
	if i==1:
		#print("hola")
		os.system('sudo bash ./90_bot-fot.sh')
	time.sleep(1)
