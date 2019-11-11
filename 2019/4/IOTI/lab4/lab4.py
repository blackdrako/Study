import numpy as np
import sympy as sy


def read_matrix(n, m, prompt=""):
    """Чтение матрицы размера n*m из стандартного ввода
    :param n: Количество строк в матрице
    :param m: Количество столбцов в матрице
    :param prompt: (Необязательно) - приглашение пользователю
    :return: Массив numpy размерности n*m, базовый тип - sympy.Rational
    """
    if prompt:
        print(prompt)
    raw = []
    while len(raw) < m*n:
        raw += input().split()
    return np.array(
        list(
            map(
                sy.Rational, raw
            )
        )
    ).reshape(n, m)


def print_matrix(matrix):
    n, m = matrix.shape
    for i in range(n):
        for j in range(m):
            print("{: >4}".format(str(matrix[i, j])), end=' ')
        print()


def find_cell(matrix):
    """ Поиск элемента матрицы (метод наименьшей стоимости). Возвращает кортеж из индексов
    :param matrix: Матрица стоимостей
    :return: Кортеж индексов
    """
    return np.unravel_index(np.argmin(matrix), matrix.shape)


basis = []


def get_first_base(a, b, c):
    """Получение первого базисного вида
    
    :param a: Запасы
    :param b: Потребности
    :param c: Матрица стоимостей
    :return: Матрица перевозок
    """
    transit = np.full(c.shape, 0, dtype=sy.Rational)
    # Копируем их, чтобы оставить исходные массивы такими же
    tmp_a = np.array(a)
    tmp_b = np.array(b)
    tmp_c = np.array(c)
    big_number = np.max(c) + 1
    # Выполняем m+n-1 шагов
    for _ in range(sum(c.shape) - 1):
        k, r = find_cell(tmp_c)
        # Если a[k] >= b[r], вычеркиваем столбец, иначе строку
        # Вычеркивание заключается в том, что заполняем Очень Большим Числом (макс. + 1)
        if tmp_a[0][k] >= tmp_b[0][r]:
            transit[k][r] = tmp_b[0][r]
            basis.append((k, r,))
            tmp_a[0][k] -= tmp_b[0][r]
            # Удаляем по оси 1, т.е., столбец
            tmp_b[0][r] = big_number
            # tmp_b = np.delete(tmp_b, r, 1)
            tmp_c[:, r] = big_number
            # tmp_c = np.delete(tmp_c, r, 1)
        else:
            transit[k][r] = tmp_a[0][k]
            basis.append((k, r,))
            tmp_b[0][r] -= tmp_a[0][k]
            # Удаляем по оси 0, т.е., строка
            tmp_a[0][k] = big_number
            # tmp_a = np.delete(tmp_a, k, 1)
            tmp_c[k, :] = big_number
            # tmp_c = np.delete(tmp_c, k, 0)
    return transit


visited = []


def go_right(matrix, i, j, start_i, start_j):
    n, m = matrix.shape
    j += 1
    to_check = []
    # Получаем все заполненные клетки (из которых потенциально можно получить цикл)
    while j < m:
        if i == start_i and j == start_j:
            return [(i, j,)]
        if matrix[i, j] or (i, j,) in basis:
            to_check.append((i, j,))
        j += 1
    for i, j in to_check:
        if (i, j,) not in visited:
            visited.append((i, j,))
            result = go_down(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
            result = go_up(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
    return []


def go_left(matrix, i, j, start_i, start_j):
    j -= 1
    to_check = []
    while j >= 0:
        if i == start_i and j == start_j:
            return [(i, j,)]
        if matrix[i, j] or (i, j,) in basis:
            to_check.append((i, j,))
        j -= 1
    for i, j in to_check:
        if (i, j,) not in visited:
            visited.append((i, j,))
            result = go_down(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
            result = go_up(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
    return []


def go_up(matrix, i, j, start_i, start_j):
    i -= 1
    to_check = []
    while i >= 0:
        if i == start_i and j == start_j:
            return [(i, j,)]
        if matrix[i, j] or (i, j,) in basis:
            to_check.append((i, j,))
        i -= 1
    for i, j in to_check:
        if (i, j,) not in visited:
            visited.append((i, j,))
            result = go_right(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
            result = go_left(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
    return []


def go_down(matrix, i, j, start_i, start_j):
    n, m = matrix.shape
    i += 1
    to_check = []
    while i < n:
        if i == start_i and j == start_j:
            return [(i, j,)]
        if matrix[i, j] or (i, j,) in basis:
            to_check.append((i, j,))
        i += 1
    for i, j in to_check:
        if (i, j,) not in visited:
            visited.append((i, j,))
            result = go_right(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
            result = go_left(matrix, i, j, start_i, start_j)
            if result:
                return [(i, j,)] + result
    return []


def make_cycle(matrix, i, j):
    """ Получает цикл для свободной переменной с индексами i,j
    :param matrix: Матрица перевозок
    :param i: Строка свободной переменной
    :param j: Столбец свободной переменной
    :return: List, содержащий кортежи индексов клеток - узлов цикла
    """
    global visited
    visited = []
    return go_right(matrix, i, j, i, j) + \
           go_left(matrix, i, j, i, j) + \
           go_up(matrix, i, j, i, j) + \
           go_down(matrix, i, j, i, j)


def sum_cycle(matrix, cycle):
    """ Подсчитывает алгебраическую сумму стоимостей по циклу пересчета
    :param matrix: Матрица перевозок
    :param cycle: Цикл пересчета
    :return: Алгебраическая сумма стоимостей по циклу пересчета
    """
    m = -1
    s = 0
    for i, j in cycle:
        s += m * matrix[i, j]
        m = -m
    return s


def shift_cycle(matrix, cycle, x):
    """ Сдвиг по циклу cycle матрицы перевозок matrix на число x
    :param matrix: Матрица перевозок
    :param cycle: Цикл пересчета
    :param x: Величина сдвига
    :return: None
    """
    m = -1
    for i, j in cycle:
        matrix[i, j] = matrix[i, j] + x * m
        m = -m


def get_gamma(base, c):
    n, m = base.shape
    gamma = np.full(base.shape, 0, sy.Rational)
    for i in range(n):
        for j in range(m):
            if not base[i, j]:
                cycle = make_cycle(base, i, j)
                gamma[i, j] = sum_cycle(c, cycle)
    return gamma


def get_negative(matrix):
    n, m = matrix.shape
    for i in range(n):
        for j in range(m):
            if matrix[i, j] < 0:
                return i, j
    return 0, 0


def to_bool(matrix):
    n, m = matrix.shape
    bool_matrix = np.full((n, m,), False)
    for i in range(n):
        for j in range(m):
            if matrix[i, j]:
                bool_matrix = True
    return bool_matrix


def __main__():

    n, m = map(int, input("Сколько в транспортной задаче баз (n) и потребителей (m) ? ").split())

    a = read_matrix(1, n, "Введите запасы: ")
    b = read_matrix(1, m, "Введите потребности: ")
    c = read_matrix(n, m, "Введите матрицу стоимостей: ")

    base = get_first_base(a, b, c)
    print("Получено первое опорное решение. Матрица перевозок: ")
    print_matrix(base)

    print("Каким методом решать - распределительный (1) или потенциалов (2)? ")
    answer = input()
    if answer == '1':
        while True:
            gamma = get_gamma(base, c)

            print("Получили значения гамм: ")
            print_matrix(gamma)

            i_min, j_min = get_negative(gamma)

            if gamma[i_min, j_min] < 0:
                # Получим цикл пересчета, и найдем x - наименьшая из перевозок, означенная - (::2 - через один элемент)
                cycle = make_cycle(base, i_min, j_min)
                # ОченьБольшоеЧисло
                x = 9999
                im, jm = 0, 0
                for i, j in cycle[::2]:
                    if base[i, j] < x:
                        x = base[i, j]
                        im, jm = i, j
                basis.remove((im, jm,))
                basis.append(cycle[-1])
                shift_cycle(base, cycle, x)
                print("Сдвинули по циклу {} на {}".format(cycle, x))
                print("Получили новое опорное решение: ")
                print_matrix(base)
            else:
                print("Решение найдено.")
                # Вывод
                print_matrix(base)
                z = 0
                for i in range(n):
                    for j in range(m):
                        z += c[i, j] * base[i, j]
                print("z min = {}".format(z))
                break
    elif answer == '2':
        while True:
            # Решение системы уравнений по-даунски
            u = np.full(n, 0, sy.Rational)
            v = np.full(m, 0, sy.Rational)
            # Примем u[0] за 0, и получим все значения v в 0-й строке
            # Зная v[j], можно вычислить все u[i], соответствующие base[i,j] в столбце j
            for j in range(m):
                if base[0][j]:
                    v[j] = c[0][j]
                    for i in range(n):
                        if base[i, j] or (i, j,) in basis:
                            u[i] = c[i, j] - v[j]
            # Знаем часть переменных, попытаемся найти остальные
            for _ in range(2):
                for i in range(n):
                    if u[i]:
                        for j in range(m):
                            if base[i, j] or (i, j,) in basis:
                                v[j] = c[i, j] - u[i]
                for j in range(m):
                    if v[j]:
                        for i in range(n):
                            if base[i, j] or (i, j,) in basis:
                                u[i] = c[i, j] - v[j]

            print("Решения системы уравнений")
            print("u = ", u)
            print("v = ", v)
            # Вычисление гамм
            gamma = np.full((n, m,), 0, sy.Rational)
            for i in range(n):
                for j in range(m):
                    gamma[i, j] = c[i, j] - (u[i] + v[j])
            print("Получили значения гамм: ")
            print_matrix(gamma)
            print()
            i_min, j_min = get_negative(gamma)
            if gamma[i_min, j_min] < 0:
                # Получим цикл пересчета, и найдем x - наименьшая из перевозок, означенная - (::2 - через один элемент)
                cycle = make_cycle(base, i_min, j_min)
                # ОченьБольшоеЧисло
                x = 9999
                im, jm = 0, 0
                for i, j in cycle[::2]:
                    if base[i, j] < x:
                        x = base[i, j]
                        im, jm = i, j
                basis.remove((im, jm,))
                basis.append(cycle[-1])
                shift_cycle(base, cycle, x)
                print("Сдвинули по циклу {} на {}".format(cycle, x))
                print("Получили новое опорное решение: ")
                print_matrix(base)
            else:
                print("Решение найдено.")
                # Вывод
                print_matrix(base)
                z = 0
                for i in range(n):
                    for j in range(m):
                        z += c[i, j] * base[i, j]
                print("z min = {}".format(z))
                break


__main__()