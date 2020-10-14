import RPi.GPIO as GPIO
import dht11

# initialize GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.cleanup()

# read data using pin 14
instance = dht11.DHT11(pin = 11)
result = instance.read()

if result.is_valid():
    print("Temperatura: " + str(result.temperature) + " C")
    print("Humitat: " + str(result.humidity) + " %")
else:
    print("Error: %d" % result.error_code)
