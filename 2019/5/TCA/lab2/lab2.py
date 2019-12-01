# -*- coding: utf-8 -*-
def custom_bin(num, sz = 5):
    return bin(num)[2:].rjust(sz, '0')

def nand(a1, a2):
    return not (a1 and a2)
def nor(a1, a2):
    return not (a1 or a2)

def s1(bits):
    x1, x2, x3, x4, x5 = tuple(map(bool, map(int, custom_bin(bits))))
    t = nand(not x1, not x3)
    z1 = nand(t, t)
    t = nand(x1, x3)
    z2 = nand(t, t)
    t = nand(x1, not x2)
    z3 = nand(t, t)
    t = nand(x4, not x3)
    z4 = nand(t, t)
    t = nand(x3, x2)
    z5 = nand(t, t)
    t = nand(not x4, not x5)
    z6 = nand(t, t)
    u1 = nand(z3, z4)
    u2 = nand(z1, not x4)
    u3 = nand(z1, x2)
    u4 = nand(z2, not x4)
    u5 = nand(z2, x2)
    u6 = nand(z5, z6)
    u7 = nand(z1, not x5)
    u8 = nand(z2, not x5)
    v3 = nand(u1, u2)
    v4 = nand(u3, u4)
    v5 = nand(u5, u6)
    v6 = nand(u7, u8)
    v1 = nand(nand(v3, v3), nand(v4, v4))
    v2 = nand(nand(v5, v5), nand(v6, v6))
    f = nand(nand(v1, v1), nand(v2, v2))
    return int(f)

def s2(bits):
    x1, x2, x3, x4, x5 = tuple(map(bool, map(int, custom_bin(bits))))
    z1 = nor(x1, x3)
    z2 = nor(nor(x1, x1), nor(x3, x3))
    z3 = nor(nor(x1, x1), x2)
    z4 = nor(nor(x4, x4), x3)
    z5 = nor(nor(x2, x2), nor(x3, x3))
    z6 = nor(x4, x5)
    u1 = nor(nor(z3, z3), nor(z4, z4))
    u2 = nor(nor(z1, z1), nor(not x4, not x4))
    u3 = nor(nor(z1, z1), nor(x2, x2))
    u4 = nor(nor(z2, z2), nor(not x4, not x4))
    u5 = nor(nor(z2, z2), nor(x2, x2))
    u6 = nor(nor(z5, z5), nor(z6, z6))
    u7 = nor(nor(z1, z1), nor(not x5, not x5))
    u8 = nor(nor(z2, z2), nor(not x5, not x5))
    t = nor(u1, u2)
    v3 = nor(t, t)
    t = nor(u3, u4)
    v4 = nor(t, t)
    t = nor(u5, u6)
    v5 = nor(t, t)
    t = nor(u7, u8)
    v6 = nor(t, t)
    t = nor(v3, v4)
    v1 = nor(t, t)
    t = nor(v5, v6)
    v2 = nor(t, t)
    t = nor(v1, v2)
    f = nor(t, t)
    return int(f)

def s3(bits):
    x1, x2, x3, x4, x5 = tuple(map(bool, map(int, custom_bin(bits))))
    z1 = nand(nand(x1, x1), x3)
    z3 = nand(x1, nand(x3, x3))
    z4 = nand(x4, x5)
    z2 = nand(nand(x2, x2), nand(z4, z4))
    u1 = nand(nand(x1, x1), nand(z2, z2))
    u2 = nand(x3, nand(z2, z2))
    u3 = nand(nand(x4, x4), nand(z3, z3))
    u4 = nand(x4, nand(z1, z1))
    u5 = nand(x2, nand(z3, z3))
    u6 = nand(x5, nand(z1, z1))
    u7 = nand(nand(x2, x2), nand(z1, z1))
    t = nand(u1, u2)
    v5 = nand(t, t)
    t = nand(u5, u6)
    v4 = nand(t, t)
    t = nand(u3, v5)
    v3 = nand(t, t)
    t = nand(u7, v4)
    v2 = nand(t, t)
    t = nand(u4, v3)
    v1 = nand(t, t)
    t = nand(v1, v2)
    f = nand(t, t)
    return int(f)

def s4(bits):
    x1, x2, x3, x4, x5 = tuple(map(bool, map(int, custom_bin(bits))))
    t = nor(x1, not x3)
    z1 = nor(t, t)
    t = nor(not x1, x3)
    z3 = nor(t, t)
    t = nor(not x4, not x5)
    z4 = nor(t, t)
    t = nor(x2, z4)
    z2 = nor(t, t)
    u1 = nor(x1, z2)
    u2 = nor(not x3, z2)
    u3 = nor(x4, z3)
    u4 = nor(not x4, z1)
    u5 = nor(not x2, z3)
    u6 = nor(not x5, z1)
    u7 = nor(x2, z1)
    v5 = nor(u1, u2)
    v4 = nor(u5, u6)
    v3 = nor(u3, nor(v5, v5))
    v2 = nor(u7, nor(v4, v4))
    v1 = nor(u4, nor(v3, v3))
    f = nor(nor(v1, v1), nor(v2, v2))
    return int(f)

var_count = 5
bit_set = 0
table = {}
print("Таблица истинности исходной функции:")
for _ in range(2**var_count):
    str_bs = custom_bin(bit_set)     # Вектор переменных x1 - x5
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

print("Таблица истинности схемы 1:")
table_1 = {}
bit_set = 0
for _ in range(2**var_count):
    table_1[bit_set] = s1(bit_set)
    print(
        '| ' + ' | '.join(list(custom_bin(bit_set) + str(table_1[bit_set]))) + ' |'
    )
    bit_set += 1
    
print("Таблица истинности схемы 2:")
table_2 = {}
bit_set = 0
for _ in range(2**var_count):
    table_2[bit_set] = s2(bit_set)
    print(
        '| ' + ' | '.join(list(custom_bin(bit_set) + str(table_2[bit_set]))) + ' |'
    )
    bit_set += 1

print("Таблица истинности схемы 3:")
table_3 = {}
bit_set = 0
for _ in range(2**var_count):
    table_3[bit_set] = s3(bit_set)
    print(
        '| ' + ' | '.join(list(custom_bin(bit_set) + str(table_3[bit_set]))) + ' |'
    )
    bit_set += 1
    
print("Таблица истинности схемы 4:")
table_4 = {}
bit_set = 0
for _ in range(2**var_count):
    table_4[bit_set] = s4(bit_set)
    print(
        '| ' + ' | '.join(list(custom_bin(bit_set) + str(table_4[bit_set]))) + ' |'
    )
    bit_set += 1

print("Исходная и схема 1 совпадают: ", table == table_1)
print("Исходная и схема 2 совпадают: ", table == table_2)
print("Исходная и схема 3 совпадают: ", table == table_3)
print("Исходная и схема 4 совпадают: ", table == table_4)