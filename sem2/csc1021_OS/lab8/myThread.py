#!/usr/bin/env python3

#  MyThread Subclass of Thread (myThread.py)

# To generalize our subclass of Thread from mtsleepE.py, we move the subclass to
# a separate module and add a getResult() method for callables that produce
# return values

import threading
from time import ctime

class MyThread(threading.Thread):
    def __init__(self, func, args, name=""):
        threading.Thread.__init__(self)
        self.name = name
        self.func = func
        self.args = args
        self.res = None     # Initialize res to avoid AttributeError

    def getResult(self):
        return self.res

    def run(self):      #  __call__() in the last program
        print("Starting", self.name, "at: ", ctime())
        self.res = self.func(*self.args)
        print(self.name, "finished at: ", ctime())

