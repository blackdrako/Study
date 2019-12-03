def custom_bin(num, sz = 5):
    return bin(num)[2:].rjust(sz, '0')

def dnf(bits):
    x1, x2, x3, x4, x5 = tuple(map(bool, map(int, custom_bin(bits))))
    z1 = not x1 and not x3
    z2 = x1 and x3
    z3 = x1 and not x2
    z4 = not x3 and x4
    z5 = x2 and x3
    z6 = not x4 and not x5
    u1 = z3 and z4
    u2 = z1 and not x4
    u3 = z1 and x2
    u4 = z2 and not x4
    u5 = z2 and x2
    u6 = z5 and z6
    u7 = z1 and not x5
    u8 = z2 and not x5
    v3 = u1 or u2
    v4 = u3 or u4
    v5 = u5 or u6
    v6 = u7 or u8
    v1 = v3 or v4
    v2 = v5 or v6
    f = v1 or v2
    return int(f)

def knf(bits):
    x1, x2, x3, x4, x5 = tuple(map(bool, map(int, custom_bin(bits))))
    z1 = x1 or not x3
    z3 = not x1 or x3
    z4 = not x4 or not x5
    z2 = x2 or z4
    u1 = x1 or z2
    u2 = not x3 or z2
    u3 = x4 or z3
    u4 = not x4 or z1
    u5 = not x2 or z3
    u6 = not x5 or z1
    u7 = x2 or z1
    v5 = u1 and u2
    v4 = u5 and u6
    v3 = u3 and v5
    v2 = u7 and v4
    v1 = u4 and v3
    f = v1 and v2
    return int(f)

var_count = 5
bit_set = 0
table = {}
print("Таблица истинности исходной функции:")
for _ in range(2**var_count):
    str_bs = custom_bin(bit_set)     # Вектор переменных x1 - x5
    if bool(eval(
         ((1)(2)(0)-(3)(4)(5))=-3
    table[bit_set] = int(
        eval(
            '-2 <= ({0} - {1}) and ({0} - {1}) < 3'.format(  # Условие -2 <=(x1x20-x3x4x5)<3
                int(str_bs[:2] + '0', 2),        # Первое выражение x1x20
                int(str_bs[2:], 2)               # Второе выражение x3x4x5
            )
        )
    )
    print(
        '| ' + ' | '.join(list(str_bs + str(table[bit_set]))) + ' |'
    )
    bit_set += 1

print("Таблица истинности схемы по ДНФ:")
table_dnf = {}
bit_set = 0
for _ in range(2**var_count):
    table_dnf[bit_set] = dnf(bit_set)
    print(
        '| ' + ' | '.join(list(custom_bin(bit_set) + str(table_dnf[bit_set]))) + ' |'
    )
    bit_set += 1
    
print("Таблица истинности схемы по КНФ:")
table_knf = {}
bit_set = 0
for _ in range(2**var_count):
    table_knf[bit_set] = knf(bit_set)
    print(
        '| ' + ' | '.join(list(custom_bin(bit_set) + str(table_knf[bit_set]))) + ' |'
    )
    bit_set += 1

print("Исходная и днф совпадают: ", table == table_dnf)
print("Исходная и кнф совпадают: ", table == table_knf)
