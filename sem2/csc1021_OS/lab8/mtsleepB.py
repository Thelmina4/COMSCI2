#!/usr/bin/env python3

# mtsleepB.py - Using Locks

import _thread
from time import sleep, ctime

loops = [4, 2]

def loop(nloop, nsec, lock):
    print(f"start loop {nloop} at:   {ctime()}")
    sleep(nsec)
    print(f"loop {nloop} done at :   {ctime()}")
    lock.release()      # realease the lock to allow another thread to run

def main():
    print(f"starting MAIN at:  {ctime()}")

    # make an array for lock
    locks = []
    nloops = range(len(loops))

    for i in nloops:
        # We first create a list of locks, which we obtain by using the
        # thread.allocate_lock() function and acquire (each lock) with the
        # acquire() method. Acquiring a lock has the effect of “locking the lock.”
        # Once it is locked, we add the lock to the lock list, locks
        lock = _thread.allocate_lock()
        lock.acquire()          #  “locking the lock.”
        locks.append(lock)

    # next loop actually spawns the threads, invoking the loop() function per thread, and
    # for each thread, provides it with the loop number, the sleep duration, and
    # the acquired lock for that thread. So why didn’t we start the threads in the
    # lock acquisition loop? There are two reasons. First, we wanted to synchronize the threads, so that all the horses started out the gate around the same
    # time, and second, locks take a little bit of time to be acquired. If your
    # thread executes too fast, it is possible that it completes before the lock has
    # a chance to be acquired
    for i in nloops:
        # start_new_thread(function, args, kwargs=None)
        # i => nloop, loops[i] => nsec, locks[i] => lock
        _thread.start_new_thread(loop, (i, loops[i], locks[i]))
        
    # It is up to each thread to unlock its lock object when it has completed
    # execution. The final loop just sits and spins (pausing the main thread)
    # until both locks have been released before continuing execution   
    for i in nloops:
        while locks[i].locked(): pass
    
    print(f"All DONE at :      {ctime()}")

if __name__ == "__main__":
    main()
