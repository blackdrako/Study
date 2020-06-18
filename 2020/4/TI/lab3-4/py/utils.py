import fractions as fr
import itertools as it
from math import log2
import getterminalsize
from os import system
from tree import Node

def get_symbols()->list:
    '''
    Считывает введенные пользователем пары символ-вероятность
    Возвращаемое значение: список из кортежей вида (символ, вероятность)
    '''
    res: list = []
    inp = "default"
    while inp != "":
        inp: str = input()
        if inp == "":
            continue
        symb, prob = inp.split()
        prob = prob.replace(",", ".")
        try:
            prob = fr.Fraction(prob)
        except ValueError:
            print("Значение вероятности - не число")
        else:
            res.append((symb, prob))
    check = fr.Fraction(0)
    for e in res:
        check += e[1]
    if abs(check-1) > 1E-5:
        print("Предупреждение: сумма вероятностей равна {}".format(check))
    return res

def get_symbols_file(strs)->list:
    '''
    Считывает введенные пользователем пары символ-вероятность
    Возвращаемое значение: список из кортежей вида (символ, вероятность)
    '''
    res: list = []
    for inp in strs:
        symb, prob = inp.split()
        prob = prob.replace(",", ".")
        try:
            prob = fr.Fraction(prob)
        except ValueError:
            print("Значение вероятности - не число")
        else:
            res.append((symb, prob))
    check = fr.Fraction(0)
    for e in res:
        check += e[1]
    if abs(check-1) > 1E-5:
        print("Предупреждение: сумма вероятностей равна {}".format(check))
    return res

def to_base(num, n, width):
    res = []
    while num:
        res.insert(0, num % n)
        num //=n
    while len(res) < width:
        res.insert(0, 0)
    return res

def make_blocks(symbols: list, n: int)->list:
    '''
    Преобразовывает список из символов в список n-грамм с вероятностями их появления
    Возвращаемое значение: список из кортежей вида (строка из n символов, вероятность)
    '''
    new_symbols = []
    for i in range(0, len(symbols)**n):
        tmpl = to_base(i, len(symbols), n)
        # print(tmpl)
        tmpc = []
        for c in tmpl:
            tmpc.append(symbols[c])
        new_symbols.append(tmpc)
    
    # for c in it.combinations_with_replacement(symbols, n):
    #     for p in it.permutations(c):
    #         if p not in new_symbols:
    #             new_symbols.append(p)
    def concat(lst):
        new_lst: list = []
        for cort in lst:
            symb: list = []
            prob: int = 1
            for item in cort:
                symb.append(item[0])
                prob *= item[1]
            new_lst.append((''.join(symb), prob))
        return new_lst
    new_symbols = concat(new_symbols)
    return new_symbols

def enthropy(symbols)->float:
    '''
    Вычисляет энтропию алфавита symbols, представленного в виде списка кортежей (символ, вероятность)
    '''
    res = 0
    for item in symbols:
        p = item[1]
        res += -p * log2(p)
    return res

def make_tree_huffman(lst):
    '''
    Возвращает дерево для построения кодов по Хаффману
    '''
    lst = list(map(Node, lst))
    while len(lst) > 1:
        lst.sort(key = lambda x:x.data[1], reverse = True)
        m1 = lst.pop()
        m2 = lst.pop()
        newdata = (m1.data[0] + m2.data[0], m1.data[1] + m2.data[1])
        lst.append(Node(newdata, m2, m1))
    return lst[0]

def make_tree_shennon(lst):
    '''
    Возвращает дерево для построения кодов по Шеннону-Фано
    '''
    if len(lst) == 1:
        return Node(lst[0])
    root = Node('.')
    plst = list(map(lambda x:x[1], lst))
    # Находим границу, по которой следует разделить алфавит
    bound = 0
    min_diff = 1
    for i in range(len(lst)):
        diff = abs(sum(plst[:i]) - sum(plst[i:]))
        if diff < min_diff:
            bound = i
            min_diff = diff
    left = lst[:bound]
    right = lst[bound:]
    if len(left) > 0:
        root.left = make_tree_shennon(left)
    else:
        root.left = None
    if len(right) > 0:
        root.right = make_tree_shennon(right)
    else:
        root.right = None
    return root

def bin_f(x, n):
    '''
    Возвращает число x в виде последовательности бит фиксированной длины n
    Если x в двоичном виде длиннее, чем n, оно обрезается
    '''
    out:str = bin(x)[2:]
    if len(out) < n:
        out = out.rjust(n, '0')
    else:
        out = out[-n:]
    return out

def encode(s, code_cort, symb_to_add):
    '''
    Возвращает строку, закодированную кодом code
    code - кортеж из типа, длины блока, и самого кода
    '''
    block = code_cort[1]
    code = code_cort[2]
    print("Разобъем сообщение {} на блоки длиной {}".format(s, block))
    for i in range(len(s)//block):
        print(s[i*block:(i+1)*block])
    to_write = len(s) % block
    # Дополняем строку первым символом кода до соответствующей длины
    if to_write != 0:
        print(s[-to_write:])
        to_write = block - to_write
        print("Последний блок неполный, необходимо дополнить его до размера {}. Допишем {} символов {}".format(block, to_write, symb_to_add))
        s += symb_to_add * to_write
    print("Теперь необходимо кодировать дополненное сообщение")
    print(s)
    input()
    # Добавляем к выходной строке размер одного блока, причем размер этот уменьшается на 1 для более плотной упаковки
    # Предположим, что размер блока не более 8 символов, и обрежем/дополним значение до трех символов
    out = bin_f(block, 3)
    out2 = out + "|"
    print("К сообщению добавляется три бита - размер блока")
    print("{} = {}".format(out, block))
    # Следующим запишем количество дописанных символов
    # Поскольку количество символов не меньше размера блока, то ограничим его также тремя битами
    out += bin_f(to_write, 3)
    out2 += bin_f(to_write, 3)
    print("и три бита - количество дописанных до кратной размеру блока длины символов")
    print("{} = {}".format(bin_f(to_write, 3), to_write))
    # n - количество блоков в сообщении
    n = len(s) // block
    for i in range(n):
        t = s[i*block:(i+1)*block]
        if t not in code:
            print("Невозможно закодировать сообщение: встретился символ, которого нет в словаре")
            return None
        out += code[t]
        out2 += "|" + code[t]
        print("{} : {}".format(t, code[t]))
    return out, out2

def turn_tables(encoder):
    '''
    По словарю для кодирования составляет словарь для декодирования
    '''
    decoder = {}
    for k in encoder.keys():
        decoder[encoder[k]] = k
    return decoder

def decode(s, code_cort):
    '''
    По закодированной строке и коду возвращает декодированную строку
    '''
    block = code_cort[1]
    decoder = turn_tables(code_cort[2])
    if block != int(s[:3], 2) + 1:
        print("Декодер не может раскодировать последовательность: не совпадает размер блока")
        return None
    to_delete = int(s[3:6], 2)
    out = ''
    left = 6
    right = left+1
    while left < len(s):
        while right <= len(s) and not s[left:right] in decoder:
            right += 1
        if right > len(s):
            print("Не удалось декодировать последовательность: не найдено совпадение среди кодовых слов.\nНомер бита, на котором произошла ошибка:", left)
        out += decoder[s[left:right]]
        left = right
    if to_delete > 0:
        return out[:-to_delete]
    else:
        return out