import numpy as np
import fractions as fr
import itertools as it
from os import system

# Функции для ввода и вывода матрицы
def fr2str(f):
    return str(f).center(7)

def print_array(a, name = ''):
    s = ' ' + np.array2string(a, formatter = {'all':fr2str})[1:-1]
    if name != '':
        w = len(s)//a.shape[0]
        s += '\n{}'.format(name.center(w))
    print(s)

def input_array(n, m, message = ""):
    print(message, end = "")
    s = []
    while len(s) < m*n:
        s += input().replace(',', '.').split()
    l = list(map(fr.Fraction, s))
    return np.array(l).reshape((n,m))

def swap_rows(matr, n1, n2):
    matr[[n1,n2]] = matr[[n2,n1]]

def swap_columns(matr, m1, m2):
    matr[:,[m1,m2]] = matr[:,[m2,m1]]

def mult_row(matr, n, x):
    '''Умножить n-ю строку матрицы на x''' 
    matr[n] *= x

def add_row(matr, n1, n2, x = 1):
    '''Умножить строку n1 матрицы на x и прибавить к n2 строке матрицы'''
    matr[n2] += matr[n1]*x

def gauss_step(matr, lead_i, lead_j):
    # Делим строку на разрешающий элемент (Если он не нулевой)
    if matr[lead_i, lead_j] == 0:
        return False
    else:
        mult_row(matr, lead_i, 1/matr[lead_i, lead_j])
        # К каждой из строк добавляем ведущую строку, умноженную на коэффициент
        for i in range(0, matr.shape[0]):
            if i != lead_i:
                mul = -matr[i, lead_j]
                add_row(matr, lead_i, i, mul)
        return True


def gauss(matr):    
    n, m = matr.shape
    # Количество строк, вошедших в треугольную матрицу
    rows_eliminated = 0
    while rows_eliminated < n:
        # lead_i, lead_j - строка и столбец с ведущим элементом
        lead_j = rows_eliminated
        lead_i = rows_eliminated
        # Ищем строку/столбец с ненулевым разрешающим элементом
        while lead_j < m and matr[lead_i, lead_j] == 0:
            if lead_i < n-1:
                lead_i += 1
            else:
                lead_i = rows_eliminated
                lead_j += 1
        if lead_j == m:
            # Не найден ненулевой элемент, т.е., получили нулевую строку. Удалим все строки ниже
            for i in range(rows_eliminated, n):
                matr = np.delete(matr, i, axis=0)
            break
        if lead_i > rows_eliminated:
            swap_rows(matr, rows_eliminated, lead_i)
            lead_i = rows_eliminated
        gauss_step(matr, lead_i, lead_j)
        rows_eliminated += 1
    return matr

def can_replace(matr, j1, j2):
    i = 0
    while i < matr.shape[0] and matr[i, j1] == 0:
        i += 1
    return matr[i, j2] != 0

def replace(matr, j1, j2):
    '''Производит операцию замещения j1-й базисной переменной и \
        j2-й свободной переменной. Если операция замещения невозможна,
        т.е., разрешающий элемент равен 0, возвращает False'''
    if can_replace(matr, j1, j2):
        i = 0
        while i < matr.shape[0] and matr[i, j1] == 0:
            i += 1
        gauss_step(matr, i, j2)

def get_bases(matr):
    '''Возвращает все базисные виды матрицы matr'''
    matr = gauss(matr)
    n, m = matr.shape
    bases = []
    success = []
    # Базисные переменные
    bases_columns = set(range(n))
    # Базисными могут быть любые n из m-1 столбцов матрицы
    for comb in map(set, it.combinations(range(m-1), n)):
        tmp = matr.copy()
        to_append = True
        # Базисные переменные, которые станут свободными
        old_bases = bases_columns - comb
        # Свободные переменные, которые станут базисными
        new_bases = comb - bases_columns
        for i in old_bases:
            j = new_bases.pop()
            if not can_replace(tmp, i, j):
                to_append = False
                break
            else:
                replace(tmp, i, j)
        if to_append:
            bases.append(tmp)
            success.append(comb)
    return bases

def oporn_plan(bases):
    # Получим все базисные виды
    oporn = []
    for b in bases:
        # Проверим, все ли элементы в последнем столбце неотрицательны
        if all(map(lambda x: x>=0, b[:,-1])):
            oporn.append(b.copy())
    return oporn

def search_opt_plan(oporn, koef):
    '''Поиск оптимального плана среди опорных решений oporn, для целевой
    функции с коэффициентами koef, стремящейся к максимуму'''
    results = []
    for p in oporn:
        s = 0
        # s - значение целевой функции
        for row in p:
            last = 0
            ex = False
            while not ex:
                j = row.tolist().index(fr.Fraction(1), last)
                if p[:,j].tolist().count(fr.Fraction(0)) != p.shape[0]-1:
                    last = j+1
                else:
                    # Свободная переменная - значение xj умножить на коэф. при xj
                    s += row[-1] * koef[j]
                    ex = True
        results.append(s)
    m = max(results)
    return oporn[results.index(m)], m
system('cls')
n, m = map(int, input("Количество уравнений и переменных?\n").split())
ar = input_array(n, m)
print_array(ar, 'Введенный массив\n')
bases = get_bases(ar)
num = 1
for b in bases:
    print_array(b, 'Базисный вид {}\n'.format(num))
    num += 1
oporn = oporn_plan(bases)
num = 1
for o in oporn:
    print_array(o, 'Опорный план {}\n'.format(num))
    num += 1
koef = list(map(fr.Fraction, \
    input("Введите коэффициенты целевой функции x{}..x{} -> max\n".format(1, 5)).split()))
# Если количество коэффициентов меньше, чем количество переменных,
# то остальные коэффициенты сочтем нулями
while len(koef) < 6-1:
    koef.append(fr.Fraction(0))
s = ""
for i in range(len(koef)-1):
    s += "{}X{}+".format(str(koef[i]), i+1)
s += "{}X{}->max".format(str(koef[-1]), 5)
print("Целевая функция:", s, "\n")

otvet = search_opt_plan(oporn, koef)
print_array(otvet[0], "Оптимальный план, полученный перебором\n")
print("Значение целевой функции {}.\n".format(otvet[1]))
input('Press ENTER for EXIT')