def ask(question = "", choices = [], default = None):
    rep = True
    while rep:
        rep = False
        n = len(choices)
        qstr = question + "\n" + "\n".join(["{} - {}".format(i+1, choices[i]) for i in range(n)]) + "\n"
        choice:str = input(qstr)
        if choice.isnumeric():
            choice = int(choice)
            if 1 <= choice <= n:
                return choice - 1
            else:
                rep = True
        else:
            rep = True