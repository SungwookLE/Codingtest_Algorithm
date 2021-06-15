import numpy as np

class practice:
    def method1(self):
        print("method1")
        print()
        
    def method2(self,arg):
        print("method2")
        print(self.a)
        print(self.c)
        print(arg)
        print()

    a = 5.01
    b = 7.1
    c = 7.99


class practice2(practice):
    def method1(self):
        print("method1 of two")
        print()

k=practice()
print()
k.method1()
k.method2("arg in")

n = practice2()
n.method1()
n.method2("arg")
