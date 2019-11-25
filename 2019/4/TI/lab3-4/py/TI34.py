from math import log2
import getterminalsize
from os import system
from tree import Node
from utils import *


max_size = getterminalsize.getTerminalSize()
width = max_size[0]

system('cls')

rep = True
while rep:
    # system('cls')
    rep = False
    choice = input("Откуда прочитать алфавит?\n1 - из файла\n2 - с клавиатуры\n")
    if choice == '1':
        # name = input("Имя файла? ")
        name = "a8.txt"
        f = open(name)
        lst = get_symbols_file(f.readlines())
        f.close()
    elif choice == '2':
        print("Введите символы и вероятности их появления: ")
        lst = get_symbols()
    else:
        rep = True


print("Введенный алфавит: ")
for x in lst:
    print(x[0], float(x[1]))

input()

rep = True
while rep:
    # system('cls')
    rep = False
    choice = input("Откуда прочитать сообщение?\n1 - из файла\n2 - с клавиатуры\n")
    if choice == '1':
        # name = input("Имя файла? ")
        name = "in8.txt"
        f = open(name)
        msg = ''.join(f.readlines())
        f.close()
        msg = msg.replace('\n', '')
    elif choice == '2':
        msg = input("Введите сообщение: ")
    else:
        rep = True

print("Введенное сообщение: ")
print(msg)

input()

first_symb = lst[0][0]
e = enthropy(lst)
lst1 = lst
big_ex_f = False
while not big_ex_f:
    ex_f = False
    while not ex_f:
        # system('cls')
        n = input("Если хотите кодировать поблочно, введите размер блока: ")
        if n != "":
            n = int(n)
            print(n)
            sz = len(lst) ** n
            if sz > 5000:
                print("Необходимо сгенерировать {} кодов. Это может занять много времени. Продолжить? да/Нет".format(sz))
                ans = input()
                if ans != "да":
                    continue
        else:
            n = 1
        ex_f = True
    if n != 1:
        lst = make_blocks(lst, n)
    else:
        lst = lst1

    lst.sort(key = lambda x: x[1], reverse = True)
    # tmp отображение вероятностей появления блоков
    print("{}-граммы и их вероятности: ".format(n))
    for x in lst:
        print(x[0], float(x[1]))
    input()
    # tmp

    rep = True
    while rep:
        # system('cls')
        rep = False
        choice = input("Какой код необходимо составить?\n1 - Шеннона-Фано\n2 - Хаффмана\n")
        if choice == '1':
            ctype = "Шеннон"
            tree = make_tree_shennon(lst)
        elif choice == '2':
            ctype = "Хаффман"
            tree = make_tree_huffman(lst)
        else:
            rep = True
    stree = str(tree)
    print()
    if max(map(len, stree.split('\n'))) > width:
        print("Дерево символов слишком велико, чтобы отобразить его.")
    else:
        print("Получившееся дерево символов:\n", stree)
    codes = tree.gen_code()
    length = sum(map(len, codes.values()))
    symbols = sorted(codes.keys())

    # Средняя длина кода это сумма p_i*l_i
    avg = sum([x[1] * len(codes[x[0]]) for x in lst]) / n
    print()
    print("Полученные коды символов:")
    for s in symbols:
        print("{} : {}".format(s, codes[s]))
    print("Энтропия:", e)
    print("Средняя длина кода (бит/символ):", float(avg))

    input()
    
    # # system('cls')
    # rep = True
    # while rep:
    #     # system('cls')
    #     rep = False
    #     choice = input("Вы хотите кодировать или декодировать сообщение?\n1 - кодировать\n2 - декодировать\n3 - выйти\n")
    #     if choice == '1':
    #         mode = "encode"
    #     elif choice == '2':
    #         mode = "decode"
    #     elif choice == '3':
    #         exit()
    #     else:
    #         rep = True
    mode = 'encode'
    if mode == "encode":
        new_msg, new_2_msg = encode(msg, (ctype, n, codes), first_symb)
    if mode == "decode":
        new_msg = decode(msg, (ctype, n, codes))
    rep = True
    while rep:
        # # system('cls')
        rep = False
        # choice = input("Куда записать сообщение?\n1 - в файл\n2 - вывести на консоль\n")
        choice = '2'
        if choice == '1':
            name = input("Имя файла? ")
            f = open(name, 'w')
            f.write(new_msg)
            f.close()
        elif choice == '2':
            if mode == "encode":
                print("\nЗакодированное сообщение:", new_2_msg)
                #print("\nРезультат в виде последовательности бит:", new_msg)
            if mode == "decode":
                print("Декодированное сообщение:", new_msg)
            input()
        else:
            rep = True
        
    choice = input("Продолжить?\n1 - да\n2 - нет\n")
    if choice == '2':
        exit()