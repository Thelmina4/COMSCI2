#!/usr/bin/env python3

# https://selkie.macalester.edu/csinparallel/modules/ParallelProcessesInPython/build/html/Coordination.html#the-join-method
# The Join Method
from multiprocessing import *
from random import randint
import time

def slowpoke(lock):
    time.sleep(2)
    lock.acquire()
    print("Slowpoke: Ok, I'm coming")
    lock.release()

def haveToWait():
    # Note also the use of a lock to manage the shared use of stdout.
    lock = Lock()
    p1 = Process(target=slowpoke, args=(lock,))
    p1.start()
    print("Waiter: Any day now...")

    # join is not always necessary for process coordination.
    #  Often a similar result can be obtained by blocking on a queue get
    p1.join()
    print("Waiter: Finally! Geez.")

if __name__ == "__main__":
    haveToWait()
