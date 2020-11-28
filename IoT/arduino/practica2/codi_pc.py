import serial
import re
import io
import sys
import datetime

ser = serial.Serial('COM3', 9600, timeout=0.5)
regex=re.compile("[0-9]{2}\.[0-9]{2}")
fitxer = io.open("temperatures.csv", "w")
fitxer2 = io.open("humitat.csv", "w")
comptador=0
while True:
    try:
        data= ser.readline()
        if b"Temp" in data:
            fitxer.write(str(datetime.datetime.now())+":")
            fitxer.write(regex.findall(str(data))[0]+"\n")
        if b"Hum" in data:
            fitxer2.write(str(datetime.datetime.now())+":")
            fitxer2.write(regex.findall(str(data))[0]+"\n")
        fitxer.flush()
        fitxer2.flush()
    except KeyboardInterrupt:
        break
fitxer.close()
fitxer2.close()
sys.exit()            