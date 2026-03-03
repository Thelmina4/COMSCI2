#!/usr/bin/env python3

# mtsleepE.py - Subclass Thread and Create Subclass Instance
# Subclassing is a bit easier to read when you are creating
# your threads

# Rather than instantiating the Thread class, we subclass it. This gives us more
# flexibility in customizing our threading objects and simplifies the thread
# creation call.
import threading
from time import sleep, ctime
from myThread import MyThread

loops = [4, 2]

#  lcass moved to myThreads.py
# class MyThread(threading.Thread):
#     def __init__(self, func, args, name=""):
#         threading.Thread.__init__(self)
#         self.name = name
#         self.func = func
#         self.args = args

#     def run(self):      #  __call__() in the last program
#         self.func(*self.args)

def loop(nloop, nsec):
    print(f"start loop {nloop} at:   {ctime()}")
    sleep(nsec)
    print(f"loop {nloop} done at :   {ctime()}")

def main():
    print(f"starting MAIN at:  {ctime()}")

    # make an array for threads
    threads = []
    nloops = range(len(loops))

    # create all threads
    for i in nloops:
        # Thread Object that represents a single thread of execution
        t = MyThread(loop, (i, loops[i]), loop.__name__)

        # in D the line was...
        # t = threading.Thread(
        #   target=Threadfunc(loop, (i, loops[i]), loop.__name__))
        threads.append(t)

    # start all the threads
    for i in nloops:
        threads[i].start()

    # wait for all threads to finish  
    for i in nloops:
        threads[i].join()
    
    print(f"All DONE at :      {ctime()}")

if __name__ == "__main__":
    main()
