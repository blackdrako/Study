import prettytable as pt
import fractions as fr

def input_array(n, m, message = ""):
    print(message, end = "")
    s = []
    while len(s) < m*n:
        s += input().replace(',', '.').split()
    l = list(map(fr.Fraction, s))
    return s

class Table:
    def __init__(self, n, m, cons, obj, baz):
        self.n = n
        self.m = m
        self.table:list = []
        self.vars = []
        self.baz = baz
        for i in range(n):
            self.table.append([cons[(i+1)*m-1]] + cons[i*m:(i+1)*m-1])
            self.vars.append("x{}".format(baz[i]))
        self.table.append([fr.Fraction(0)] + koef)

    def display(self):
        self.ptheader = ["Базисн.", "Своб."] + ["x{}".format(i) for i in range(1, self.m)]
        x = pt.PrettyTable(self.ptheader)
        for i in range(self.n):
            x.add_row([self.vars[i]] + self.table[i])
        x.add_row(["z"] + self.table[-1])
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
            if self.table[i][j] >= 0:
                pos.append(i)
        if len(pos) == 0:
            print("Целевая функция неограничена, решений нет")
            return
        min = pos[0]
        for i in pos:
            if self.table[i][0] / self.table[i][j] < self.table[min][0] / self.table[min][j]:
                min = i
        i = min
        # i,j - генеральный элемент
        print("Базисн. {} -> своб., своб. x{} -> базисн.".format(self.vars[i], j))
        p = self.table[i][j]
        for k in range(len(self.table[i])):
            self.table[i][k] /= p
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
baz = []
for i in range(n):
    s += input().replace(',', '.').split()
    baz.append(int(input("Какая из этих переменных является базисной? ")))
l = list(map(fr.Fraction, s))

koef = list(map(fr.Fraction,
            input("Введите коэффициенты целевой функции x{}..x{} -> max\n".format(1, m)).split()))
koef = list(map(lambda x: -x, koef))
tbl = Table(n, m+1, l, koef, baz)
tbl.display()
# tbl.next()
while not tbl.is_last():
    tbl.next()
#for i in range(10):
#    tbl.next()
print("Ответ: z_max = {}".format(tbl.table[-1][0]))
for i in range(len(tbl.table)-1):
    print("{} = {}".format(tbl.vars[i], tbl.table[i][0]))
#s = "z = "
#for i in range(len(koef)-1):
#    s += "{}X{}+".format(str(koef[i]), i+1)
#s += "{}X{}->max".format(str(koef[-1]), 5)
#print("Целевая функция:", s, "\n")
input('Press ENTER to EXIT')