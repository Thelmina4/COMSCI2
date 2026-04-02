from atexit import register
from random import randrange
from threading import BoundedSemaphore, Lock, Thread
from time import sleep, ctime

lock = Lock()
MAX = 5
candytray = BoundedSemaphore(MAX)


def refill():
    with lock:
        print("Refilling candy...", end=" ")
        try:
            candytray.release()
        except ValueError:
            print("full, skipping")
        else:
            print("OK")


def buy():
    with lock:
        print("Buying candy...", end=" ")
        if candytray.acquire(blocking=False):
            print("OK")
        else:
            print("empty, skipping")


def producer(loops):
    for _ in range(loops):
        refill()
        sleep(randrange(3))


def consumer(loops):
    for _ in range(loops):
        buy()
        sleep(randrange(3))


def _main():
    print("starting at:", ctime())
    nloops = randrange(2, 6)
    print(f"THE CANDY MACHINE (full with {MAX} bars)!")
    Thread(target=consumer, args=(randrange(nloops, nloops + MAX + 2),)).start()  # buyer
    Thread(target=producer, args=(nloops,)).start()  # vndr


@register
def _atexit():
    print("all DONE at:", ctime())


if __name__ == "__main__":
    _main()