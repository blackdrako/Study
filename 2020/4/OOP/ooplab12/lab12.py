import numpy as np
from math import sin
from math import cos
import scipy.integrate as si
import matplotlib.pyplot as plt


# Правая часть уравнения
def function(args, t):
    # Константы
    I = 1
    l_1 = 0.5
    l_2 = 1
    k_1 = 10000
    k_2 = 15000   
    m_1 = 5
    m_2 = 1
    n_1 = 1
    n_2 = 0.8
    # Распаковываем набор переменных
    x, fi, v, w = args
         
    return [v,
            w,
            (-k_1*(x-l_1*sin(fi))) / m_1,
            ((l_1*k_1*(x-l_1*sin(fi)))-k_2*l_2*sin(fi)) /I]
def main():
    # Задаем константы
    first = 0.0
    last = 5
    step = 0.05
    # Массив точек, по которым интегрируем
    t = np.arange(first, last, step)
    # Начальное условие, массив, каждый элемент которого - началье значение параметра в точке first
    y0 = [-0.2, 0.2, 0, 0]
    
    solution = si.odeint(function, y0, t)
    print(solution)

    plt.plot(t, solution[:, :2])

    plt.plot(t, solution[:, 0], 'g', label='FI_1(t)')
    plt.plot(t, solution[:, 1], 'r', label='FI_2(t)')
    # plt.plot(t, solution[:, 2], 'g', label='V(t)')
    # plt.plot(t, solution[:, 3], 'b', label='W(t)')
    plt.legend(loc='best')
    plt.xlabel('t')
    plt.grid()
    plt.show()


if __name__ == "__main__":
    main()
