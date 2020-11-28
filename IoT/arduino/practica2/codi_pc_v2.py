import serial
import re
import io
import sys
import datetime

ser = serial.Serial('COM3', 9600, timeout=0.5)
regex=re.compile("[0-9]{2}\.[0-9]{2}")
fitxer = io.open("dades.csv", "w")
while True:
    try:
        data= ser.readline()
        if data != b"":
            fitxer.write(str(datetime.datetime.now())+";")
            fitxer.write(str(data))
            fitxer.write(";")
            fitxer.write("\n")
        fitxer.flush()
    except KeyboardInterrupt:
        break
fitxer.close()
sys.exit()            