#!/usr/bin/env python3

# mtsleepC.py - Create Thread Instance, Passing in Function
# The Thread class from the threading module has a join() method that lets the
# main thread wait for thread completion.

import threading
from time import sleep, ctime

loops = [4, 2]
#  Gone are the locks that we had to implement when
# using the thread module.
# Instead, we create a set of Thread objects. When
# each Thread is instantiated, we dutifully pass in the function (target) and
# arguments (args) and receive a Thread instance in return. 
# The biggest difference between instantiating Thread (calling Thread()) and invoking
# thread.start_new_thread() is that the new thread does not begin execution right away.
#  This is a useful synchronization feature, especially when
# you don’t want the threads to start immediately

# note how there is no lock this time
def loop(nloop, nsec):
    print(f"start loop {nloop} at:   {ctime()}")
    sleep(nsec)
    print(f"loop {nloop} done at :   {ctime()}")

def main():
    print(f"starting MAIN at:  {ctime()}")

    # make an array for threads
    threads = []
    nloops = range(len(loops))

    for i in nloops:
        # Thread Object that represents a single thread of execution
        t = threading.Thread(target=loop, args=(i, loops[i]))
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

# # output
# lab8$ python3 mtsleepC.py
# starting MAIN at:  Tue Mar  3 12:17:32 2026
# start loop 0 at:   Tue Mar  3 12:17:32 2026
# start loop 1 at:   Tue Mar  3 12:17:32 2026
# loop 1 done at :   Tue Mar  3 12:17:34 2026
# loop 0 done at :   Tue Mar  3 12:17:36 2026
# All DONE at :      Tue Mar  3 12:17:36 2026
