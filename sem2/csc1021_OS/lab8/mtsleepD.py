#!/usr/bin/env python3

# mtsleepD.py - Create Thread Instance, Passing in Callable Class Instance
# not recommended to use as it is more difficult to work with
import threading
from time import sleep, ctime

loops = [4, 2]

class Threadfunc:
    def __init__(self, func, args, name=""):
        self.name = name
        self.func = func
        self.args = args

    def __call__(self):
        self.func(*self.args)

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
        t = threading.Thread(
            target=Threadfunc(loop, (i, loops[i]), loop.__name__))
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

# lab8$ python3 mtsleepD.py 
# starting MAIN at:  Tue Mar  3 12:31:52 2026
# start loop 0 at:   Tue Mar  3 12:31:52 2026
# start loop 1 at:   Tue Mar  3 12:31:52 2026
# loop 1 done at :   Tue Mar  3 12:31:54 2026
# loop 0 done at :   Tue Mar  3 12:31:56 2026
# All DONE at :      Tue Mar  3 12:31:56 2026