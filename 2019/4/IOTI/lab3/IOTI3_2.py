import prettytable as pt
import fractions as fr
import ask
import artif_baz

# def input_array(n, m, message = ""):
#     print(message, end = "")
#     s = []
#     while len(s) < m*n:
#         s += input().replace(',', '.').split()
#     l = list(map(fr.Fraction, s))
#     return l

class Table:

    def transform_obj(self, obj):
        new_k = []
        m = []
        t = 0
        for x in self.baz:
            new_k.append([])
            i = 0
            while self.table[i][x] == 0:
                i += 1
            for j in range(1, self.m):
                if j == x:
                    new_k[t].append(0)
                else:
                    new_k[t].append(-self.table[i][j])
            new_k[t].append(self.table[i][0])
            m.append(obj[x-1])
            obj[x-1] = 0
            t += 1
        for i in range(len(new_k)):
            for j in range(len(new_k[i])):
                obj[j] += m[i] * new_k[i][j]
        return obj

    def __init__(self, n, m, cons, obj, baz):
        self.n = n
        self.m = m
        self.table:list = []
        self.vars = []
        self.baz = baz
        # Коэффициент M - задачи
        self.M = 10 * max(max(cons), max(obj))
        print("M =", self.M)

        for i in range(n):
            self.table.append([cons[(i+1)*m-1]] + cons[i*m:(i+1)*m-1])

        # Добавим искуственные переменные
        t = obj.pop()
        while len(self.baz) < n:
            self.baz.append(self.m)
            obj.append(-self.M)
            self.m += 1
            print("baz", self.baz)
        obj.append(t)
        for j in range(self.n):
            for i in range(0, j):
                self.table[i].append(fr.Fraction(0))
            self.table[j].append(fr.Fraction(1))
            for i in range(j+1, self.n):
                self.table[i].append(fr.Fraction(0))

        obj = self.transform_obj(obj)
        out = "Выразим базисные переменные через свободные. Получена новая целевая функция:\nz = " + ''.join("%+ix%i" % (obj[i], i+1) for i in range(len(obj))) + "%+i" % obj[-1]
        print(out)

        for i in range(self.n):
            self.vars.append("x{}".format(self.baz[i]))
        self.table.append([obj[-1]] + obj[:-1])
        for j in range(1, self.m):
            self.table[-1][j] = -self.table[-1][j]

    def display(self):
        self.ptheader = ["Базисн.", "Своб."] + ["x{}".format(i) for i in range(1, self.m)]
        x = pt.PrettyTable(self.ptheader)
        for i in range(self.n):
            x.add_row([self.vars[i]] + self.table[i])
        x.add_row(["z_M"] + self.table[-1])
        print(x)
    
    def is_last(self):
        j = 1
        while j < self.m and self.table[-1][j] >= 0:
            j += 1
        if j == self.m:
            return True
        else:
            return False
    
    def next(self):
        j = 1
        while j < self.m and self.table[-1][j] >= 0:
            j += 1
        pos = []
        for i in range(n):
            if self.table[i][j] > 0:
                pos.append(i)
        if len(pos) == 0:
            print("Целевая функция неограничена, решений нет")
            return
        min = 0
        for i in pos:
            if self.table[i][0] / self.table[i][j] < self.table[min][0] / self.table[min][j]:
                min = i
        i = min
        # i,j - генеральный элемент
        print("Базисн. {} -> своб., своб. x{} -> базисн.".format(self.vars[i], j))
        for k in range(len(self.table[i])):
            self.table[i][k] /= self.table[i][j]
        for l in range(len(self.table)):
            if l == i:
                continue
            m = -self.table[l][j] / self.table[i][j]
            for k in range(len(self.table[l])):
                self.table[l][k] += m*self.table[i][j]
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

        
n, m = map(int, input("Сколько в системе ограничений уравнений и переменных?\n").split())
print("Введите коэффициенты уравнений: ")
s = []
for i in range(n):
    s += input().replace(',', '.').split()
l = list(map(fr.Fraction, s))

koef = list(map(fr.Fraction,
           input("Введите коэффициенты целевой функции x{}..x{} -> max\n".format(1, m)).split()))
baz = []
tbl = Table(n, m+1, l, koef, baz)
tbl.display()
while not tbl.is_last():
    tbl.next()
while True:
    tbl.next_ignore()
    input()
print("Ответ: z_max = {}".format(tbl.table[-1][0]))
for i in range(len(tbl.table)-1):
    print("{} = {}".format(tbl.vars[i], tbl.table[i][0]))

#         choice = ask.ask(question="Каким способом воспользоваться для решения?", choices = ["метод искуственного базиса", "метод больших штрафов"])
        #if choice == 0:
        #    print("da")
        #    while len(self.baz) < n:
        #        self.baz.append(self.m)
        #        self.m += 1
        #    for j in range(self.n):
        #        for i in range(0, j):
        #            self.table[i].append(fr.Fraction(0))
        #        self.table[j].append(fr.Fraction(1))
        #        for i in range(j+1, self.n):
        #            self.table[i].append(fr.Fraction(0))