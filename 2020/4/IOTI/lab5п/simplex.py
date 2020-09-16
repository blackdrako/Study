from prettytable import PrettyTable


# Таблица симплекс-метода
class Table:
    def __init__(self, restrictions, free_koefficients, objective, basis_variables, basis_in_lines, z_name = "z"):
        self.n = len(restrictions)
        self.m = len(restrictions[0])
        self.matrix = [
            [free_koefficients[i]] + restrictions[i] for i in range(self.n)
        ]
        self.matrix.append(
            [objective[0]] + [-objective[i] for i in range(1, len(objective))]
        )
        self.basis_variables = basis_variables
        self.basis_in_lines  = basis_in_lines
        self.z_name = z_name
        # Получаем заголовок для таблицы
        self.ptheader = ["Базисн.", "Своб."] + ["x{}".format(i) for i in range(1, self.m+1)]
        self.chosen = []

    def __str__(self):
        pt = PrettyTable(self.ptheader)
        for i in range(self.n):
            pt.add_row(
                ["x{}".format(self.basis_in_lines[i])] +
                self.matrix[i]
            )
        # Строка целевой функции
        pt.add_row([self.z_name] + self.matrix[-1])
        return str(pt)
    
    def get_negative(self, start = 1):
        j = start
        while j < self.m and self.matrix[-1][j] >= 0:
            j += 1
        if j == self.m:
            return 0
        else:
            return j
    
    def step(self, i, j):
        # 1) Разделить строку на значение генерального элемента
        t = self.matrix[i][j]
        for k in range(len(self.matrix[i])):
            self.matrix[i][k] /= t
        # 2) К каждой строке матрицы прибавить i-ю строку, умножив ее на такое число, что в j-м столбце получается 0
        for l in range(len(self.matrix)):
            if l == i:
                continue
            m = -self.matrix[l][j] / self.matrix[i][j]
            for k in range(len(self.matrix[l])):
                self.matrix[l][k] += m*self.matrix[i][k]

    def after_step(self, i, j):
        old_basis = self.basis_in_lines[i]
        new_basis = j
        self.basis_variables[
            self.basis_variables.index(old_basis)
        ] = new_basis
        self.basis_in_lines[i] = new_basis

    def next(self):
        # Получаем максимальное по модулю отрицательное
        j = self.matrix[-1].index(
            min(
                self.matrix[-1][1:]
                )
        )
        if self.matrix[-1][j] >= 0:
            return False
        while j in self.chosen:
            print("Выбрана базисная переменная x{}, которая уже была выбрана ранее.\nВероятно, алгоритм симплекс-метода зациклился. Выбираем другой разрешающий элемент\n".format(j))
            j = self.get_negative(j+1)
        if not j:
            return False
        self.chosen.append(j)
        positives = []
        for i in range(self.n):
            if self.matrix[i][j] > 0:
                positives.append(i)
        if not positives:
            # Целевая функция неограничена, решений нет
            return False
        minimum = positives[0]
        for i in positives:
            if (self.matrix[i][0] / self.matrix[i][j]) < (self.matrix[minimum][0] / self.matrix[minimum][j]):
                minimum = i
        i = minimum
        # i,j - генеральный элемент
        print("Базисн. x{} -> своб., своб. x{} -> базисн.".format(self.basis_in_lines[i], j))
        # Теперь выполняем операцию замещения. 
        self.step(i, j)
        # 3) Записываем новые значения для базисных переменных. Базисная переменная i-й строки стала свободной, свободная пер. j-го столбца стала базисной
        self.after_step(i, j)
        return True

    # Эта часть относится только к методу искуственного базиса

    def artificial_basis(self):
        return max(self.basis_variables) > self.m

    def kick_artificials(self):
        # Для того, чтобы вывести искуственные переменные из числа базисных, возьмем первую попавшуюся иск. пер. среди базисных
        # и первую попавшуюся свободную, и произведем операцию замещения
        i = 0
        while self.basis_in_lines[i] <= self.m - self.n:
            i += 1
        # i - строка, соотв. базисной переменной, которую мы исключаем. Теперь выберем свободную - найдем столбец, который не входит в базисные п. и при этом генеральный элемент не будет равен 0
        j = 1
        while (j in self.basis_variables or self.matrix[i][j] == 0) and j < self.m:
            j += 1
        # Вообще-то этого не должно произойти, но вдруг...
        if j == self.m:
            return False
        # Проведем замещение
        print("Базисн. x{} -> своб., своб. x{} -> базисн.".format(self.basis_in_lines[i], j))
        self.step(i, j)
        # Поменяем значения базисных переменных
        self.after_step(i, j)
        return True
    
    def export(self):
        # Экспортируем все то, что передается конструктору
        restrictions = [
            row[1:] for row in self.matrix[:-1]
        ]
        free_koefficients = [
            row[0] for row in self.matrix
        ]
        objective = self.matrix[-1]
        basis_in_lines = self.basis_in_lines
        basis_variables = self.basis_variables
        z_name = self.z_name
        return (restrictions, free_koefficients, objective, basis_variables, basis_in_lines, z_name)