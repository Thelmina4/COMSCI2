#!/usr/bin/env python3

# mtsleepA.py
# The same loops from onethr.py are executed, but this time using the simple
# multithreaded mechanism provided by the thread module. The two loops are
# executed concurrently (with the shorter one finishing first, obviously), and the
# total elapsed time is only as long as the slowest thread rather than the total time for
# each separately.
import _thread
from time import sleep, ctime

def loop0():
    print(f"start loop 0 at:   {ctime()}")
    sleep(4)
    print(f"loop 0 done at :   {ctime()}")

def loop1():
    print(f"Start loop 1 at:   {ctime()}")
    sleep(2)
    print(f"Loop 1 done at :   {ctime()}")

def main():
    print(f"starting MAIN at:  {ctime()}")
    # note how the () is moved in the next line
    # Spawns a new thread and executes function
    # with the given args and optional kwargs
    # start_new_thread(function, args, kwargs=None)
    _thread.start_new_thread(loop0, ())
    _thread.start_new_thread(loop1, ())

    # ìf I change the sleep time then the loop threads don't complete
    #  if we did not stop
    # the main thread from continuing, it would proceed to the next statement,
    # displaying “all done” and exit, killing both threads running loop0() and
    # loop1()
    sleep(6)
    
    print(f"All DONE at :      {ctime()}")

if __name__ == "__main__":
    main()

# output: threads run concurrently
# lab8$ python3 mtsleepA.py
# starting MAIN at : Tue Mar  3 11:25:58 2026
# start loop 0 at: Tue Mar  3 11:25:58 2026
# Start loop 1 at: Tue Mar  3 11:25:58 2026
# Loop 1 done at : Tue Mar  3 11:26:00 2026
# loop 0 done at : Tue Mar  3 11:26:02 2026
# All DONE at : Tue Mar  3 11:26:04 2026

# sleep(2)
# lab8$ python3 mtsleepA.py 
# starting MAIN at : Tue Mar  3 11:34:31 2026
# start loop 0 at: Tue Mar  3 11:34:31 2026
# Start loop 1 at: Tue Mar  3 11:34:31 2026
# All DONE at : Tue Mar  3 11:34:33 2026