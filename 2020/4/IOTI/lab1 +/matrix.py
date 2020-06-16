# │ ┌ ┐ └ ┘ ┴ ┬ ├ ─ ┼
class matrix:
    def __init__(self, n, m, init_m = [], name = ""):
        if init_m == []:
            self.a = [[0 for j in range(m)] for i in range(n)]
        else:
            self.a = [[init_m[j+i*m] for j in range(m)] for i in range(n)]
        self.n = n
        self.m = m
        self.name = name
    def __str__(self):
        widths = [0 for i in range(self.m)]
        for j in range(self.m):
            for i in range(self.n):
                widths[j] = max(widths[j], len("{}".format(self.a[i][j])))
        if self.n == 1:
            retstr = "[{0}]".format(' '.join(["{}".format(self.a[0][i]).rjust(widths[i]) for i in range(self.m)]))
        else:
            retstr = "┌ {0} ┐\n".format(' '.join(["{}".format(self.a[0][i]).rjust(widths[i]) for i in range(self.m)]))
            for row in self.a[1:-1]:
                retstr += "│ {0} │\n".format(' '.join(["{}".format(row[i]).rjust(widths[i]) for i in range(self.m)]))
            retstr += "└ {0} ┘".format(' '.join(["{}".format(self.a[-1][i]).rjust(widths[i]) for i in range(self.m)]))
        if self.name != "":
            pos = (sum(widths) + self.m - 1 + 4 - len(self.name)) // 2
            retstr = retstr + '\n' + ' ' * pos + self.name
        return retstr
    def __getitem__(self, key):
        return self.a[key]
    def __copy__(self):
        new_m = matrix(self.n, self.m, self.to_list(), self.name)
        return new_m
    def to_list(self):
        list_m = []
        for x in self.a:
            for y in x:
                list_m.append(y)
        return list_m
    def sum_column(self):
        """ Суммирование по столбцам. Возвращает лист из сумм"""
        sums = [0 for i in range(self.m)]
        for row in self.a:
            for j in range(self.m):
                sums[j] += row[j]
        return sums
    def sum_rows(self):
        return [sum(row) for row in self.a]
    def multiply_columns(self, vector):
        """ Умножение столбцов на вектор"""
        new_matr = self.__copy__()
        for i in range(new_matr.n):
            for j in range(new_matr.m):
                new_matr.a[i][j] *= vector[i]
        return new_matr
    def multiply_rows(self, vector):
        """ Умножение строк на вектор"""
        new_matr = self.__copy__()
        for i in range(new_matr.n):
            for j in range(new_matr.m):
                new_matr.a[i][j] *= vector[j]
        return new_matr
    def divide_columns(self, vector):
        """ Деление столбцов на вектор"""
        new_matr = self.__copy__()
        for i in range(new_matr.n):
            for j in range(new_matr.m):
                new_matr.a[i][j] /= vector[i]
        return new_matr
    def divide_rows(self, vector):
        """ Деление строк на вектор"""
        new_matr = self.__copy__()
        for i in range(new_matr.n):
            for j in range(new_matr.m):
                new_matr.a[i][j] /= vector[j]
        return new_matr