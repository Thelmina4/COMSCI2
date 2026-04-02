from multiprocessing import *

# Anonymous Processes
def sayHi3(n):
    print("Hi", n , "from process", current_process().name, "- pid", current_process().pid)

def manyGreetings():
    print("Hi from process", current_process().pid, "(parent process)")
    personName = "thelmina"

    for i in range(100):
        Process(target=sayHi3, args=(personName,), name=str(i)).start()
        # the above line is the same as the 2 below. 
        # the one-line version includes the use of anonymous Process objects
        # We’re then just calling the start method on that Process object,
        # instead of storing it in a variable and calling start on that variable
        # p = Process(target=sayHi3, args=(personName,), name=str(i))
        # p.start()
 
if __name__ == "__main__":
    ### execute
    manyGreetings()