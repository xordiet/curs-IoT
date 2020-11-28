import serial
import re
import matplotlib.pyplot as plt
import datetime

ser = serial.Serial('COM3', 9600, timeout=0.5)
ser.close()
ser.open()

while True:
    plt.title("Gràfic combinat")
    plt.ion()
    t1=plt.text(2,102, "", fontsize=12)
    t2=plt.text(10,110, "", fontsize=12)
    t3=plt.text(10,102, "", fontsize=12)
    xdata = []
    ydata = []
    axes = plt.gca()
    axes.set_xlim(1, 12)
    axes.set_ylim(0, 100)
    line, = axes.plot(xdata, ydata, 'r-')
    compta = 0
    while compta <13:
        data = str(ser.readline())
        d= data.split(';')
        if len(d) > 2:
            print(d[1]+";"+d[2])
            compta += 1
            xdata.append(compta)
            ydata.append(float(d[1]))
            line.set_xdata(xdata)
            line.set_ydata(ydata)
            currentDT = datetime.datetime.now()
            t1.set_text(str(currentDT.hour)+":"+str(currentDT.minute)+":"+str(currentDT.second))
            t2.set_text("T.: "+d[1]+" ºC")
            t3.set_text("H.: "+d[2]+" %")
            plt.plot()
            plt.pause(1e-17)
    plt.clf()