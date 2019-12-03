# -*- coding: utf-8 -*-
# Импорты, много их
import sys
import numpy as np
import json
import scipy.integrate as si
import math
from matplotlib.backends.qt_compat import QtCore, QtWidgets, is_pyqt5
if is_pyqt5():
    from matplotlib.backends.backend_qt5agg import (
        FigureCanvas, NavigationToolbar2QT as NavigationToolbar)
else:
    from matplotlib.backends.backend_qt4agg import (
        FigureCanvas, NavigationToolbar2QT as NavigationToolbar)

from matplotlib.figure import Figure


# Правая часть уравнений
# В моем случае система задана следующим образом
# d2x/dt2 = -kx/m
# d2phi/dt2 = (l1^2 k1 tg(phi) - l2^2 k2 tg(phi) / I
# Приведем систему к диф. уравнениям первого порядка (просто введем промежуточные функции), и получим:
# dx/dt = v
# dv/dt = -k1x/m1
# dphi/dt = omega
# domega/dt = ((l1**2) * k1 * math.tan(phi) - (l2**2) * k2 * math.tan(phi))/I
# Соответственно так и записываем выражение в return

g = 9.8
    
I = 1
    
m1 = 10
m2 = 10
    
I1 = 5
I2 = 5
    
k1 = 7000
k2 = 5000

def function(args, t):
    # Константы

    # Распаковываем набор переменных
    phi1, omega1, phi2, omega2 = args

    return [
        omega1,
        (-m1*g*phi1*(1/6)*l - k1*((1/3)*l*phi1-(1/3)*l*phi2)*(1/3)*l - k2*((2/3)*l*phi1-(2/3)*l*phi2)*(2/3)*l)/I1,
        omega2,
        (-m2*g*phi2*(1/6)*l - k1*((1/3)*l*phi2-(1/3)*l*phi1)*(1/3)*l - k2*((2/3)*l*phi2-(2/3)*l*phi1)*(2/3)*l)/I2
        ]

class NumpyEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        return json.JSONEncoder.default(self, obj)


# Чисто вспомогательная обертка, возвращает пару иксы - массив игреков
def calculate(first, last, steps, y0, func):
    t = np.linspace(first, last, steps)
    
    with open("D:\\Output.txt", "w") as text_file:
        text_file.write(json.dumps(si.odeint(func, y0, t),cls=NumpyEncoder))
        text_file.close()
    with open("D:\\t.txt", "w") as text_file:
        text_file.write(json.dumps(t))
        text_file.close()
    return t, si.odeint(func, y0, t)


def replot():
    t, y = calculate(first, last, steps, y0, function)



if __name__ == "__main__":
    # Значения по умолчанию - начальное, конечное t, количество отрезков разбиения
    first = 0.0
    last = 1
    steps = 100

    g=float(sys.argv[5])
    I=float(sys.argv[6])
    m1=float(sys.argv[7])
    m2=float(sys.argv[8])
    I1=float(sys.argv[9])
    I2=float(sys.argv[10])
    k1=float(sys.argv[11])
    k2=float(sys.argv[12])
    last=float(sys.argv[13])
    
    # Начальные условия (условия задачи Коши). Идут по порядку: x, v, phi, omega
    print(sys.argv[1],sys.argv[2],sys.argv[3],sys.argv[4], sys.argv[5],sys.argv[6],sys.argv[7],sys.argv[8],sys.argv[9],sys.argv[10],sys.argv[11],sys.argv[12])
    y0 = [float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3]), float(sys.argv[4])]
    replot()
