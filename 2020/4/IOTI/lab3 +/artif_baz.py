import prettytable as pt
import fractions as fr

off_constraints = False

class Table:
    def is_baz(self, j):
        i = 0
        has_1 = False
        is_baz_ = True
        while i < self.n and is_baz_:
            if self.table[i][j] == 1:
                if has_1:
                    is_baz_ = False
                has_1 = True
            else:
                if self.table[i][j] != 0:
                    is_baz_ = False
            i += 1
        return is_baz_

    def get_baz(self):
        baz = []
        for j in range(1, self.m):
            if self.is_baz(j):
                baz.append(j)
        return baz

    def __init__(self, n, m, cons):
        self.n = n
        self.m = m
        self.table:list = []
        self.vars = []
        self.baz = []
        obj = [fr.Fraction(0) for i in range(m)]
        for i in range(n):
            self.table.append([cons[(i+1)*m-1]] + cons[i*m:(i+1)*m-1])

        # Сделаем свободные члены положительными
        for i in range(n):
            if self.table[i][0] < 0:
                for j in range(m):
                    self.table[i][j] *= -1
        # Создадим целевую функцию f
        for i in range(n):
            obj[0] -= self.table[i][0]
            for j in range(1, m):
                obj[j] += self.table[i][j]

        out = "Получена новая целевая функция:\nf = " + ''.join("%+ix%i" % (obj[i], i) for i in range(1, len(obj))) + "%+i" % obj[0]
        print(out)

        while len(self.baz) < n:
            self.baz.append(self.m)
            self.m += 1
        for j in range(self.n):
            for i in range(0, j):
                self.table[i].append(fr.Fraction(0))
            self.table[j].append(fr.Fraction(1))
            for i in range(j+1, self.n):
                self.table[i].append(fr.Fraction(0))
        for i in range(self.n):
            self.vars.append("x{}".format(self.baz[i]))
        self.table.append(obj)
        while len(self.table[-1]) < self.m:
            self.table[-1].append(fr.Fraction(0))
        for j in range(1, self.m):
            self.table[-1][j] = -self.table[-1][j]

    def display(self):
        self.ptheader = ["Базисн.", "Своб."] + ["x{}".format(i) for i in range(1, self.m)]
        x = pt.PrettyTable(self.ptheader)
        for i in range(self.n):
            x.add_row([self.vars[i]] + self.table[i])
        x.add_row(["f"] + self.table[-1])
        print(x)
    
    def is_last(self):
        j = 1
        while j < self.m and self.table[-1][j] >= 0:
            j += 1
        if j == self.m:
            return True
        else:
            return False
    
    def is_bazisn(self):
        m = max(self.get_baz())
        return m < self.m - self.n

    def next(self):
        global off_constraints
        if off_constraints:
            b = self.m - self.n
            i = 0
            while self.baz[i] < b:
                i += 1
            j = 1
            while self.table[i][j] == 0:
                j += 1
        else:
            j = 1
            while j < self.m and self.table[-1][j] >= 0:
                j += 1
            pos = []
            for i in range(self.n):
                if self.table[i][j] > 0:
                    pos.append(i)
            if len(pos) == 0:
                print("Для исключения оставшихся искуственных переменных необходимо нарушить правило выбора разрешающего элемента")
                off_constraints = True
                return
            min = 0
            for i in pos:
                if self.table[i][0] / self.table[i][j] < self.table[min][0] / self.table[min][j]:
                    min = i
            i = min
        # i,j - генеральный элемент
        print("Базисн. {} -> своб., своб. x{} -> базисн.".format(self.vars[i], j))
        d = self.table[i][j]
        for k in range(len(self.table[i])):
            self.table[i][k] /= d
        for l in range(len(self.table)):
            if l == i:
                continue
            m = -self.table[l][j] / self.table[i][j]
            for k in range(len(self.table[l])):
                self.table[l][k] += m*self.table[i][k]
        self.baz[i] = j
        self.vars[i] = "x{}".format(j)
        self.display()

    def next_ignore(self):
        # Необходимо найти генеральный элемент, с помощью которого можно вывести из числа базисных переменных искуственную.
        # Будем просматривать строку, соотв. искуственной базисн. переменной в поисках положительного числа
        b = self.m - self.n
        i = 0
        while self.baz[i] < b:
            i += 1
        j = 1
        while self.table[i][j] == 0:
            j += 1
        # i,j - генеральный элемент
        print("Базисн. {} -> своб., своб. x{} -> базисн.".format(self.vars[i], j))
        d = self.table[i][j]
        for k in range(len(self.table[i])):
            self.table[i][k] /= d
        for l in range(len(self.table)):
            if l == i:
                continue
            m = -self.table[l][j] / self.table[i][j]
            for k in range(len(self.table[l])):
                self.table[l][k] += m*self.table[i][k]
        self.baz[i] = j
        self.vars[i] = "x{}".format(j)
        self.display()
    
    def return_lst(self):
        r = []
        for i in range(self.n):
            for j in range(1, self.m - self.n):
                r.append(self.table[i][j])
            r.append(self.table[i][0])
        return r


def find_baz(l, n, m):
    print("Решаем вспомогательную задачу:")
    tbl = Table(n, m+1, l)
    tbl.display()
    while not tbl.is_last():
        tbl.next()
    print("Получен допустимый базисный вид исходной системы ограничений. Применим симплекс-метод в стандартном виде")
    
    return tbl.return_lst(), tbl.baz
