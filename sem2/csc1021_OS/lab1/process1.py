#!/usr/bin/env python3
from multiprocessing import *

def sayHi():
    print("Hi from process", current_process().pid)
def sayHiAgain():
    print("Hi from processes again", current_process().pid)

def procEx():
    print("Hi from process", current_process().pid, "(parent process)")

    otherProc1 = Process(target=sayHi, args=())
    # otherProc2 = Process(target=sayHi, args=())
    # otherProc3 = Process(target=sayHi, args=())
    otherProc1.start()
    # otherProc2.start()
    # otherProc3.start()

    # join() makes the main process wait until the child process finishes
    # otherProc.join() 

if __name__ == "__main__":
    ### execute
    procEx()