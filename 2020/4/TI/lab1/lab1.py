import math
import re

flag = True
while flag:
    hartley = str(input("Вероятности появления символов одинаковы? да/Нет: "))
    if hartley.lower() == "да" or hartley.lower() == "д" or hartley.lower() == "y":
        try:
            n = int(input("Введите количество символов: "))
        except:
            print("Ошибка в вводе")
        else:
            print("Количество информации в каждом сообщении I = {0:.3} бит".format(math.log2(n)))
    else:
        sprobs = str(input("Введите вероятности появления символов в алфавите: "))
        sprobs = sprobs.replace(',', '.')
        probs = []
        try:
            for s in sprobs.split():
                if re.match(r'\d+/\d+', s) != None:
                    a, b = list(map(int, s.split("/")))
                    to_ap = a/b
                else:
                    to_ap = float(s)
                if to_ap != 0:
                    probs.append(to_ap)
        except:
            print("Ошибка в вводе")
        else:
            if abs(sum(probs) - 1) > 0.001:
                print("Вероятности сообщений не образуют полную группу!")
            else:
                N = len(probs)
                I = list(map(lambda x: -math.log2(x), probs))
                H = -sum(map(lambda x: x*math.log2(x), probs))
                if H < 0:
                    H *= -1
                H_h = math.log2(N)
                print("Энтропия по Шеннону H_ш = {0:.3} бит".format(H))
                print("Количество информации в отдельных сообщениях: ")
                for x in I:
                    print("{:.3}".format(x), end = ' ')
                print()
                print("Энтропия по Хартли H_х = {0:.3} бит".format(H_h))
                print("Коэффициент избыточности k = {0:.3}".format(1-H/H_h))
    answer = str(input("Продолжить исполнение? Да/нет: ")).lower()
    if answer == "н" or answer == "нет"or answer == "n":
        flag = False
input('Press ENTER for EXIT')