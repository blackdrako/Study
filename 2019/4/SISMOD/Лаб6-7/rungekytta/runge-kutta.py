import numpy as np
import scipy.integrate as si
import matplotlib.pyplot as plt


# Правая часть уравнения
def function(args, t):
    # Константы
    g = 9.8
    n = 8
    k = 3
    m = 2

    # Распаковываем набор переменных
    x, v = args

    return [v,g - (x-n)*k/m]


def main():
    # Задаем константы
    first = 0.0
    last = 10.0
    step = 0.0001
    # Массив точек, по которым интегрируем
    x = np.arange(first, last, step)
    # Начальное условие, массив, каждый элемент которого - начальное значение параметра в точке first
    y0 = [0.0, 0.0]
    #
    solution = si.odeint(function, y0, x)
    print(solution[0])

    plt.plot(x, solution)
    plt.show()


if __name__ == "__main__":
    main()
input('Press ENTER to EXIT')
