#!/usr/bin/env python3
# # mtsleepF.py 

# an application that spawns a random number of threads,
#  each of which outputs when it has completed

from atexit import register
from random import randrange
from threading import Thread, Lock, current_thread
from time import sleep, ctime

class CleanOutputSet(set):
    def __str__(self):
        return ", ".join(x for x in self)
    
lock = Lock()
loops = (randrange(2, 5) for _ in range(randrange(3, 7)))
remaining = CleanOutputSet()

def loop(nsec):
    myname = current_thread().name
    with lock:
        remaining.add(myname)
        print(f"[{ctime()}]     Started     [{myname}]")

    sleep(nsec)

    with lock:
        remaining.remove(myname)
        print(f"[{ctime()}]     completed    {myname}   ({nsec} secs)")
        print(f" (remining: {remaining or 'NONE left'})")

def _main():
    for pause in loops:
        Thread(target=loop, args=(pause,)).start()

@register
def _atexit():
    print("all done at:", ctime())

if __name__ == "__main__":
    _main()

# [Tue Mar 10 09:55:45 2026] Started Thread-1 (loop)
# [Tue Mar 10 09:55:45 2026] Started Thread-2 (loop)
# [Tue Mar 10 09:55:45 2026] Started Thread-3 (loop)
# [Tue Mar 10 09:55:45 2026] Started Thread-4 (loop)
# [Tue Mar 10 09:55:45 2026] Started Thread-5 (loop)
# [Tue Mar 10 09:55:47 2026] completed Thread-3 (loop) (2 secs)
#  (remining: Thread-4 (loop), Thread-2 (loop), Thread-1 (loop), Thread-5 (loop))
# [Tue Mar 10 09:55:48 2026] completed Thread-5 (loop) (3 secs)
#  (remining: Thread-4 (loop), Thread-2 (loop), Thread-1 (loop))
# [Tue Mar 10 09:55:48 2026] completed Thread-1 (loop) (3 secs)
#  (remining: Thread-4 (loop), Thread-2 (loop))
# [Tue Mar 10 09:55:48 2026] completed Thread-4 (loop) (3 secs)
#  (remining: Thread-2 (loop))
# [Tue Mar 10 09:55:49 2026] completed Thread-2 (loop) (4 secs)
#  (remining: NONE left)