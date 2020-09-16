from tree import *
class Task(object):
        def __init__(self,namefile,k):
                self.namefile = namefile
                self.k = k
        def info(self):
                print(self.namefile)
                print(self.k)
                print(self.list), print(len(self.list))
                print(self.new_list), print(len(self.new_list))
        def read_file(self):
                f = open(self.namefile)
                self.list = [line.strip() for line in f]
                f.close()
        def get_new_list(self):
                self.new_list = []
                i = 1
                temp = self.list[0]
                lenght = len(self.list)
                while i < lenght:
                        temp += self.list[i]
                        self.new_list.append(temp)
                        i += 1

t = Task('test.txt',13)
t.read_file()
t.get_new_list()
t.info()

