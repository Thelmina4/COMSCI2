# process_multi.py

# thread.py
from multiprocessing import Process

def my_fun(c):
    while True:
        pass

for i in range(3):
    Process(target=my_fun, args=(1000,)).start()