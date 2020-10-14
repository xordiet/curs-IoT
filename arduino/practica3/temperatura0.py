import serial
import re
import matplotlib.pyplot as plt
import datetime

ser = serial.Serial('COM3', 9600, timeout=0.5)
regex=re.compile("[0-9]{2}\.[0-9]{2}")
ser.close()
ser.open()

while True:
    plt.title("Gràfic temperatura")
    plt.ion()
    t1=plt.text(10,43, "", fontsize=12)
    t2=plt.text(10,41, "", fontsize=12)
    xdata = []
    ydata = []
    axes = plt.gca()
    axes.set_xlim(1, 12)
    axes.set_ylim(10, 40)
    line, = axes.plot(xdata, ydata, 'r-')
    compta = 0
    while compta <13:
        data = ser.readline()
        print(data)
        '''     
        if "Temp" in data.decode():
            compta += 1
            xdata.append(compta)
            ydata.append(float(regex.findall(str(data))[0]))
            line.set_xdata(xdata)
            line.set_ydata(ydata)
            currentDT = datetime.datetime.now()
            t1.set_text(str(currentDT.hour)+":"+str(currentDT.minute)+":"+str(currentDT.second))
            t2.set_text(regex.findall(str(data))[0]+" ºC")
            plt.plot()
            plt.pause(1e-17)
       '''
    plt.clf()