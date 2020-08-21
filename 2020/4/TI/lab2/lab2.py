import math
from matrix import *
import ui
import os

def print_ch_l(l):
    s = ""
    for i in range(len(l)):
        s += str(l[i])+ ' '
    return s
    
def enthropy(a):
    s = 0
    for i in range(a.n):
        for j in range(a.m):
            if a[i][j] != 0:
                s += a[i][j] * math.log2(a[i][j])
    return -s

def cond_enthropy(a, b):
    s = 0
    for i in range(a.n):
        for j in range(a.m):
            if a[i][j] != 0:
                s += a[i][j] * math.log2(b[i][j])
    return -s

exit_flag = True
while exit_flag:
    os.system('cls')
    f = False
    while not f:
        choice = input("Какую канальную матрицу вы хотите ввести?\n1-КМ со стороны источника, 2-КМ со стороны приемника, 3-общая КМ: ")
        f = choice in ["1", "2", "3"]
    choice = int(choice)
    n = input("Количество символов в алфавите источника? ")
    n = int(n)
    m = int(input("Количество символов в алфавите приемника? "))
    inp = []
    print("Введите матрицу ({0} чисел): ".format(n*m))
    while (len(inp) < n*m):
        inp += list(map(float, input().replace(',', '.').split()))        
    if choice == 1:
        # Со стороны источника
        src_matr = matrix(n, m, inp, "P(B/A)")
        check_list = src_matr.sum_rows()
        check_flag = True
        for i in range(len(check_list)):
            if abs(check_list[i]-1) > 0.0001:
                check_flag = False
                print("Суммы значений случайных величин по строкам: ", print_ch_l(check_list), ". Проверьте входные данные")
                break
        if check_flag:
            print("Суммы значений по строкам равны 1. ")
            inp = []
            print("Введите вероятности появления символов источника ({0} чисел): ".format(n))
            while (len(inp) < n):
            	inp += list(map(float, input().replace(',', '.').split()))
            src_add = matrix(1, n, inp, "P(A)")
            common_matr = src_matr.multiply_columns(src_add.to_list())
            common_matr.name = "P(A,B)"
            dest_add = matrix(1, m, common_matr.sum_column(), "P(B)")
            dest_matr = common_matr.divide_rows(dest_add.to_list())
            dest_matr.name = "P(A/B)"
    elif choice == 2:
        # Со стороны приемника
        dest_matr = matrix(n, m, inp, "P(A/B)")
        check_list = dest_matr.sum_column()
        check_flag = True
        for i in range(len(check_list)):
            if abs(check_list[i]-1) > 0.0001:
                check_flag = False
                print("Суммы значений случайных величин по столбцам: ", check_list, ". Проверьте входные данные")
                break
        if check_flag:
            print("Суммы значений по столбцам равны 1. ")
            inp = []
            print("Введите вероятности появления символов приемника ({0} чисел): ".format(m))
            while (len(inp) < m):
            	inp += list(map(float, input().replace(',', '.').split()))
            dest_add = matrix(1, m, inp, "P(B)")
            common_matr = dest_matr.multiply_rows(dest_add.to_list())
            common_matr.name = "P(A,B)"
            src_add = matrix(1, n, common_matr.sum_rows(), "P(A)")
            src_matr = common_matr.divide_columns(src_add.to_list())
            src_matr.name = "P(B/A)"
    elif choice == 3:
        # Общая
        check_flag = True
        s = sum(inp)
        if abs(s-1) > 0.0001:
            print("Сумма всех значений случайных величин равна ", sum, ". Проверьте входные данные")
            check_flag = False
        else:
            print("Сумма всех значений случайных величин равна 1.")
        if check_flag:
            common_matr = matrix(n, m, inp, "P(A,B)")
            src_add = matrix(1, n, common_matr.sum_rows(), "P(A)")
            src_matr = common_matr.divide_columns(src_add.to_list())
            src_matr.name = "P(B/A)"
            dest_add = matrix(1, m, common_matr.sum_column(), "P(B)")
            dest_matr = common_matr.divide_rows(dest_add.to_list())
            dest_matr.name = "P(A/B)"
    if check_flag:
        print("Полученные канальные матрицы и вероятности появления символов: ", src_matr, src_add, common_matr, dest_matr, dest_add, sep = '\n\n')
        enth_a = abs(sum(map(lambda x: x*math.log2(x), src_add.to_list())))
        enth_b = abs(sum(map(lambda x: x*math.log2(x), dest_add.to_list())))
        enth_ab = abs(cond_enthropy(common_matr, dest_matr))
        enth_ba = abs(cond_enthropy(common_matr, src_matr))
        enth_common = abs(enthropy(common_matr))
        inf_common = enth_a+enth_b-enth_common
        print("Вычисленные значения энтропии\nH(A): {0:.2}\tH(B): {1:.2}\nH(B/A): {2:.2}\tH(A/B): {3:.2}\nH(A,B): {4:.2}\tI(A,B): {5:.2}".format(enth_a, enth_b, enth_ba, enth_ab, enth_common, inf_common))
