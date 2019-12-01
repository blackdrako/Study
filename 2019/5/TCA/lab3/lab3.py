
import itertools

# Количество переменных
var_count = 5

def original_form(vars):
    if bool(
        eval(
            "(0b{0}{1}0 - 0b{2}{3}{4}) == -3".format(
                int(vars[0]),
                int(vars[1]),
                int(vars[2]),
                int(vars[3]),
                int(vars[4])
            )
        )
    ):
        return -1
    else:
        return int(
            eval(
                "-2 <= (0b{0}{1}0 - 0b{2}{3}{4}) < 3".format(
                    int(vars[0]),
                    int(vars[1]),
                    int(vars[2]),
                    int(vars[3]),
                    int(vars[4])
                )
            )
        )

def dnf_bool(vars):
    x1 = bool(int(vars[0]))
    x2 = bool(int(vars[1]))
    x3 = bool(int(vars[2]))
    x4 = bool(int(vars[3]))
    return (
        (x1 and x3)
        or
        (not x1 and not x3)
        or
        (x1 and not x2 and x4)
        or
        (not x1 and x2 and not x4)
    )

def dnf_schema(vars):
    x1 = bool(int(vars[0]))
    x2 = bool(int(vars[1]))
    x3 = bool(int(vars[2]))
    x4 = bool(int(vars[3]))
    nx1 = not x1
    nx2 = not x2
    nx3 = not x3
    nx4 = not x4
    z1 = x1 and nx2
    z2 = nx1 and x2
    u1 = x1 and x3
    u2 = nx1 and nx3
    u3 = x4 and z1
    u4 = nx4 and z2
    v1 = u1 or u2
    v2 = u3 or u4
    f = v1 or v2
    return f

def knf_bool(vars):
    x1 = bool(int(vars[0]))
    x2 = bool(int(vars[1]))
    x3 = bool(int(vars[2]))
    x4 = bool(int(vars[3]))
    return (
        (x1 or x2 or not x3)
        and
        (not x1 or x3 or x4)
        and
        (x1 or not x3 or not x4)
        and
        (not x1 or not x2 or x3)
    )

def knf_schema(vars):
    x1 = bool(int(vars[0]))
    x2 = bool(int(vars[1]))
    x3 = bool(int(vars[2]))
    x4 = bool(int(vars[3]))
    nx1 = not x1
    nx2 = not x2
    nx3 = not x3
    nx4 = not x4
    z1 = x1 or nx3
    z2 = nx1 or x3
    u1 = x2 or z1
    u2 = x4 or z2
    u3 = nx4 or z1
    u4 = nx2 or z2
    v1 = u1 and u2
    v2 = u3 and u4
    f = v1 and v2
    return f

def print_table(t):
    ind = 0
    for x in map(''.join, itertools.product('01', repeat=var_count)):
        print(
            '| ' + x + '|' + str(int(t[ind])).rjust(2) + ' |'
        )
        ind+=1

# Набор значений исходной функции
f_original = []
for x in map(''.join, itertools.product('01', repeat=var_count)):
    f_original.append(original_form(x))

print("Исходная таблица истинности:")
print_table(f_original)

f_dnf_bool = []
for x in map(''.join, itertools.product('01', repeat=var_count)):
    f_dnf_bool.append(dnf_bool(x))

print("После минимизации в виде ДНФ:")
print_table(f_dnf_bool)

f_dnf_schema = []
for x in map(''.join, itertools.product('01', repeat=var_count)):
    f_dnf_schema.append(dnf_schema(x))

print("Комбинационная схема:")
print_table(f_dnf_schema)

print("Таблица истинности схемы и формулы совпадают: ", f_dnf_bool == f_dnf_schema)

f_knf_bool = []
for x in map(''.join, itertools.product('01', repeat=var_count)):
    f_knf_bool.append(knf_bool(x))

print("После минимизации в виде КНФ:")
print_table(f_knf_bool)

f_knf_schema = []
for x in map(''.join, itertools.product('01', repeat=var_count)):
    f_knf_schema.append(knf_schema(x))

print("Комбинационная схема:")
print_table(f_knf_schema)

print("Таблица истинности схемы и формулы совпадают: ", f_knf_bool == f_knf_schema)