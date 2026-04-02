#!/usr/bin/env python3
# code in notes on loop, he will upload it later
# going to run 9 Process
# do a LookupErrordoing 10 children processes, they're not doing anthing
# just in a LookupError
# then go to terminal and go tp "top"
# can see the processes running.

# then run : pstree -p | grep 1030 -C 109
#  google the next line to make sure that it works
# killall python

from multiprocessing import Process 
# Explicit import is clearer
import random
import os

def do_a_loop():
    # Adding a print so you can see the PID to grep in your terminal
    print(f"Child process started with PID: {os.getpid()}")
    while True:
        # This will run for a long time
        if random.randint(1, 100000000) == 1:
            break

def main():
    processes = []
    # Creating 10 children as per your notes
    print(f"PARENT process started with PID: {os.getpid()}")
    for i in range(10):
        p = Process(target=do_a_loop)
        p.start()
        processes.append(p)

    # Optional: waits for them to finish so the main script doesn't end early
    for p in processes:
        p.join()

if __name__ == "__main__":
    main()
