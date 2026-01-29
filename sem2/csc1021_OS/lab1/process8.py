#!/usr/bin/env python3

# https://selkie.macalester.edu/csinparallel/modules/ParallelProcessesInPython/build/html/Coordination.html#the-join-method
# 
# Obtaining a Result from a Single Child
from multiprocessing import *
import time

def addTwoNumbers(a, b, q):
    time.sleep(2)
    q.put(a+b)

def addTwoPar():
    x = int(input("Num plz: "))
    y = int(input("Num plz: "))

    q = Queue()
    p1 = Process(target=addTwoNumbers, args=(x, y, q))
    p1.start()

    # block other processes
    # p1.join()

    # the get will already cause the parent process to block until data is on the queue. 
    result = q.get()
    print("the sum = ", result)
    
if __name__ == "__main__":
    # execute
    addTwoPar()