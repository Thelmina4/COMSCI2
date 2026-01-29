from multiprocessing import *

# Creating multiple child processes
def sayHi(name):
    print("Hi", name , "from process", current_process().pid)

def manyGreetings():
    print("Hi from process", current_process().pid, "(main process)")
    name = input("What is your name? ")
    numIDs = int(input("How many processes do you want to create? "))

    # the comma after name is used in single-element tuples to
    # distinguish them from the other use of parentheses
    for i in range(numIDs):
        Process(target=sayHi, args=(name,)).start()

if __name__ == "__main__":
    ### execute
    manyGreetings()