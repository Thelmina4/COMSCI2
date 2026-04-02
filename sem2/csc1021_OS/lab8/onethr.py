#!/usr/bin/env python3

from time import sleep, ctime

def loop0():
    print(f"start loop 0 at: {ctime()}")
    sleep(4)
    print(f"loop 0 done at : {ctime()}")

def loop1():
    print(f"Start loop 1 at: {ctime()}")
    sleep(2)
    print(f"Loop 1 done at : {ctime()}")

def main():
    print(f"starting MAIN at : {ctime()}")
    loop0()
    loop1()
    print(f"All DONE at : {ctime()}")

if __name__ == "__main__":
    main()