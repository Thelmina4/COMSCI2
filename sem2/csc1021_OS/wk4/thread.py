# thread.py
from threading import Thread

def my_fun(c):
    while True:
        pass

for i in range(3):
    Thread(target=my_fun, args=(1000,)).start()