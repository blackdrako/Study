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

#    Выполняем ввод исходных данных

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

# Здесь начинаются различия в методах. Большая часть кода дублируется, i don't care

choice = ask("Каким методом вы хотите решить задачу?", 
            ["Метод искуственного базиса", 
            "Метод больших штрафов"], 
            0)

if choice == 0:
    # Преобразование для метода искуственного базиса. Вспомогательная целевая функция приобретает вид [-sum_i b[i], sum_i x_i1, sum_i x_i2, ...]
    additional_objective = [-sum(free_koefficients)]
    additional_objective.extend(restrictions[0])
    for i in range(1, len(restrictions)):
        for j in range(0, len(restrictions[i])):
            additional_objective[j+1] += restrictions[i][j]


    for i in range(n):
        restrictions[i].extend([0 for i in range(n)])
        restrictions[i][m+i] = 1
        additional_objective.append(Fraction(0))

    print("Вспомогательная целевая функция:\n", printable_objective(additional_objective))

    # Номера столбцов, содержащих базисные переменные
    basis_variables = [i + m + 1 for i in range(n)]
    # Для каждой строки - столбец с базисной переменной
    basis_in_lines  = [i + m + 1 for i in range(n)]

    print(basis_variables, basis_in_lines)

    ab_tbl = Table(restrictions, free_koefficients, additional_objective, basis_variables, basis_in_lines, z_name = "f")
    print(ab_tbl)
    while ab_tbl.next():
        print(ab_tbl)
    print("Таблица является последней в решении вспомогательной задачи")
    # Если среди базисных переменных все еще остаются искуственные, необходимо их принудительно перевести в разряд свободных
    if ab_tbl.artificial_basis():
        print("Выведение оставшихся искуственных переменных из состава базисных")
        while ab_tbl.artificial_basis() and ab_tbl.kick_artificials():
            print(ab_tbl)

    # После того, как мы решили вспомогательную задачу, мы можем отбросить искусственные переменные и вставить в таблицу новую целевую функцию, чтобы получить уже необходимую нам таблицу.
    restrictions, free_koefficients, additional_objective, basis_variables, basis_in_lines, z_name = ab_tbl.export()

    # Отбросим и.п.
    restrictions = [
        row[:-n] for row in restrictions
    ]

    # Теперь необходимо исключить новые базисные переменные из оригинальной целевой функции
    expressions = []
    for i in range(len(restrictions)):
        # Идем по строкам, basis_in_lines[i] - номер столбца с базисной переменной очередной строки
        expressions.append([free_koefficients[i]])
        for j in range(len(restrictions[i])):
            if j != basis_in_lines[i]-1:
                expressions[i].append(-restrictions[i][j])
            else:
                expressions[i].append(Fraction(0))

    print(printable_matrix(expressions))

    for i in basis_variables:
        # k - множитель, с которым в целевую функцию входила базисная переменная
        k = objective[i]
        objective[i] = 0
        for j in range(len(objective)):
            objective[j] += k * expressions[
                basis_in_lines.index(i)
            ][j]

    print("После исключения базисных переменных целевая функция стала иметь следующий вид:\n", printable_objective(objective))

    tbl = Table(restrictions, free_koefficients, objective, basis_variables, basis_in_lines)

    # Решаем основную задачу

    print(tbl)

    while tbl.next():
        print(tbl)

# Метод больших штрафов

elif choice == 1:
    # Определим M, на которое будем домножать иск. пер.
    M = max(map(max, restrictions))     # - максимум из системы ограничений
    M = max(M, max(free_koefficients))  # - сравним и со свободными членами
    M = max(M, max(objective))          # - и с целевой функцией
    M *= 10
    print("Выбрано число M = {}".format(M))

    # Добавим в целевую функцию и ограничения искуственные базисные переменные
    for i in range(n):
        restrictions[i].extend([0 for i in range(n)])
        restrictions[i][m+i] = 1
        objective.append(-M)
    
    # Номера столбцов, содержащих базисные переменные
    basis_variables = [i + m + 1 for i in range(n)]
    # Для каждой строки - столбец с базисной переменной
    basis_in_lines  = [i + m + 1 for i in range(n)]
    
    # Необходимо исключить искуственные базисные переменные из полученной целевой функции
    expressions = []
    for i in range(len(restrictions)):
        # Идем по строкам, basis_in_lines[i] - номер столбца с базисной переменной очередной строки
        expressions.append([free_koefficients[i]])
        for j in range(len(restrictions[i])):
            if j != basis_in_lines[i]-1:
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

    tbl = Table(restrictions, free_koefficients, objective, basis_variables, basis_in_lines, z_name = "zM")
    print(tbl)
    while tbl.next():
        print(tbl)
    print("Таблица является последней в решении задачи")

# Это конец, задача должна быть решена (если, конечно, она вообще решается)

print("Теперь можно прочесть решение задачи:")
print("Z_max = {}".format(tbl.matrix[-1][0]))
for i in range(m):
    if (i+1) in basis_variables:
        print("x{} = {}".format(i+1, tbl.matrix[basis_in_lines.index(i+1)][0]))
    else:
        print("x{} = 0".format(i+1))