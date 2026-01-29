from multiprocessing import *
from random import randint

# https://selkie.macalester.edu/csinparallel/modules/ParallelProcessesInPython/build/html/Communication.html
# Communication
import time

def greet(q):
    print("(child process) Waiting for name...", current_process().pid)
    name = q.get()
    print("(child process) Well, hi", name, current_process().pid)

def sendName():
    q = Queue()

    p1 = Process(target=greet, args=(q,))
    p1.start()

    # If we comment out the time.sleep() function, it just does it faster.
    # sleep is just to demonstrate what is happening
    # the child process will go to sleep until it has a reason to wake up
    #  – in this case, that there is something to get off the queue.
    time.sleep(5) # wait for 5 seconds
    print("(parent process) Ok, I'll send the name", current_process().pid)
    q.put("Jimmy")

# BREAK BETWEEN

def greet2(q):
    print("(child process) Waiting for name...", current_process().pid)
    name = q.get()
    print("(child process) Well, hi", name, current_process().pid)

def sendName2():
    q = Queue()

    # p1 = Process(target=greet, args=(q,))
    # p1.start()
    names = ["thelma", "|James", "Ann", "Naimg", "Sean"]
    for n in names:
        Process(target=greet, args=(q,)).start()
        time.sleep(2) # wait for 2 seconds
        print("(parent process) Ok, I'll send the name", current_process().pid)
        q.put(n)

# BREAK BETWEEN

def greet3(q):
    for i in range(5):
        print("(child process) Waiting for name", i, current_process().pid)
        name = q.get()
        print("(child process) Well, hi", name, current_process().pid)

def sendName3():
    q = Queue()
    p1 = Process(target=greet3, args=(q,))
    p1.start()

    for i in range(5):
        time.sleep(randint(1,4))
        print("(main process) Ok, I'll send the name", current_process().pid)
        q.put("George"+str(i)+ " "+str(current_process().pid))
 
if __name__ == "__main__":
    ### execute

    # sendName()
    # sendName2()
    sendName3()