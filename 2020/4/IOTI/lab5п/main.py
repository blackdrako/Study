from fractions import Fraction
from simplex import Table
from ask import ask


# Функция возвращает печатный вид матрицы
def printable_matrix(matrix):
    return '\n'.join(
        ' '.join(
            str(x).rjust(3) for x in line
        ) for line
        in matrix)


def printable_objective(objective):
    s = ''
    for i in range(1, len(objective)):
        if objective[i]:
            if s:
                if objective[i] > 0:
                    s += '+'
            s += "{}x{}".format(objective[i], i)
    if objective[0] >= 0:
        s += '+'
    s += "{}".format(objective[0])
    s += "->max"
    return s


def __main__():
    n, m = map(int, input("Сколько в системе ограничений уравнений и переменных?\n").split())

    # Ввод ограничений
    print("Введите коэффициенты уравнений: ")
    str_restrictions = []
    for i in range(n):
        str_restrictions.append(input().replace(',', '.').split())

    restrictions = []
    free_koefficients = []
    for line in str_restrictions:
        casted = [Fraction(t) for t in line]
        # Запишем ограничения так: свободные члены в одномерном векторе, остальные коэффициенты в матрице
        free_koefficients.append(casted[-1])
        restrictions.append(casted[:-1])
        del casted

    del str_restrictions

    # Ввод целевой функции

    str_objective = input("Введите целевую функцию:\n").replace(',', '.').split()
    objective = [Fraction(t) for t in str_objective]
    # В целевой функции также на первом месте стоит свободный член
    objective = [objective[-1]] + objective[:-1]

    # Если встречаются строки, в которых свободный член отрицателен, необходимо домножить строку на 1
    for i in range(len(free_koefficients)):
        if free_koefficients[i] < 0:
            free_koefficients[i] *= -1
            restrictions[i] = [-x for x in restrictions[i]]

        # Определим M, на которое будем домножать иск. пер.
        M = max(map(max, restrictions))  # - максимум из системы ограничений
        M = max(M, max(free_koefficients))  # - сравним и со свободными членами
        M = max(M, max(objective))  # - и с целевой функцией
        M *= 10
        print("Выбрано число M = {}".format(M))

        # Добавим в целевую функцию и ограничения искуственные базисные переменные
        for i in range(n):
            restrictions[i].extend([0 for i in range(n)])
            restrictions[i][m + i] = 1
            objective.append(-M)

        # Номера столбцов, содержащих базисные переменные
        basis_variables = [i + m + 1 for i in range(n)]
        # Для каждой строки - столбец с базисной переменной
        basis_in_lines = [i + m + 1 for i in range(n)]

        # Необходимо исключить искуственные базисные переменные из полученной целевой функции
        expressions = []
        for i in range(len(restrictions)):
            # Идем по строкам, basis_in_lines[i] - номер столбца с базисной переменной очередной строки
            expressions.append([free_koefficients[i]])
            for j in range(len(restrictions[i])):
                if j != basis_in_lines[i] - 1:
                    expressions[i].append(-restrictions[i][j])
                else:
                    expressions[i].append(Fraction(0))

        for i in basis_variables:
            # k - множитель, с которым в целевую функцию входила базисная переменная
            k = objective[i]
            objective[i] = 0
            for j in range(len(objective)):
                objective[j] += k * expressions[
                    basis_in_lines.index(i)
                ][j]

        print("Вспомогательная целевая функция:\n", printable_objective(objective))

        tbl = Table(restrictions, free_koefficients, objective, basis_variables, basis_in_lines, z_name="zM")
        print(tbl)
        while tbl.next():
            print(tbl)
        print("Таблица является последней в решении задачи")
    print("Теперь можно прочесть решение задачи:")
    print("Z_max = {}".format(tbl.matrix[-1][0]))
    for i in range(m):
        if (i + 1) in basis_variables:
            print("x{} = {}".format(i + 1, tbl.matrix[basis_in_lines.index(i + 1)][0]))
        else:
            print("x{} = 0".format(i + 1))

__main__()
input('Press ENTER for EXIT')