def get_user_input(question, strict = False):
    """ До тех пор, пока пользователь не введет да/нет (д/н, y/n, yes/no)
    задавать вопрос. Если strict = False, считать нажатие любой клавиши кроме нет за "да"
    """
    while True:
        answer = str(input(question + " Да/нет ")).lower()
        answer = answer.lower()
        if answer == "н" or answer == "нет" or answer == "n" or answer == "no":
            return False
        elif answer == "д" or answer == "да" or answer == "y" or answer == "yes" or not strict:
            return True