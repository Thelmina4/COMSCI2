# mtfacfib.py

#!/usr/bin/env python3

# Fibonacci, Factorial, Summation (mtfacfib.py)
# In this MT application, we execute three separate recursive functions—first in a
# single-threaded fashion, followed by the alternative with multiple threads.

from time import sleep, ctime
from myThread import MyThread

def fib(x):
    sleep(0.005)
    if x < 2: return 1
    return fib(x-2) + fib(x-1)

def fac(x):
    sleep(0.1)
    if x < 2: return 1
    return x * fac(x-1)

def sumF(x):
    sleep(0.1)
    if x < 2: return 1
    return x + sumF(x-1)

funcs = [fib, fac, sumF]
n = 12

def main():
    nfuncs = range(len(funcs))

    print("*** SINGLE THREAD")

    for i in nfuncs:
        print(f"starting {funcs[i].__name__} at:  {ctime()}")
        print(funcs[i](n))
        print(funcs[i].__name__, "finishsed at :", ctime())

    print("\n*** MULTIPLE THREADS")
    threads = []

    # create all threads
    for i in nfuncs:
        # Thread Object that represents a single thread of execution
        t = MyThread(funcs[i], (n, ), funcs[i].__name__)
        threads.append(t)

    # start all the threads
    for i in nfuncs:
        threads[i].start()

    # wait for all threads to finish  
    for i in nfuncs:
        threads[i].join()
        print(threads[i].getResult())
    
    print(f"All DONE at :      {ctime()}")

if __name__ == "__main__":
    main()

# lab8$ python3 mtfacfib.py 
# *** SINGLE THREAD
# starting fib at:  Tue Mar  3 13:17:24 2026
# 233
# fib finishsed at : Tue Mar  3 13:17:27 2026
# starting fac at:  Tue Mar  3 13:17:27 2026
# 479001600
# fac finishsed at : Tue Mar  3 13:17:28 2026
# starting sumF at:  Tue Mar  3 13:17:28 2026
# 78
# sumF finishsed at : Tue Mar  3 13:17:29 2026

# *** MULTIPLE THREADS
# Starting fib at:  Tue Mar  3 13:17:29 2026
# Starting fac at:  Tue Mar  3 13:17:29 2026
# Starting sumF at:  Tue Mar  3 13:17:29 2026
# fac finished at:  Tue Mar  3 13:17:30 2026
# sumF finished at:  Tue Mar  3 13:17:30 2026
# fib finished at:  Tue Mar  3 13:17:32 2026
# 233
# 479001600
# 78
# All DONE at :      Tue Mar  3 13:17:32 2026
# lab8$ 