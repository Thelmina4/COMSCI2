from multiprocessing import *

# https://selkie.macalester.edu/csinparallel/modules/ParallelProcessesInPython/build/html/ExecutionOrderAndResources.html

# Execution Order & resource contention

# Suppose process A acquires the lock and begins printing.
# If processes B, C, and D then execute their acquire calls while A has the lock,
# then B, C, and D each must wait.
# That is, each will block on its acquire call.
def sayHi4(lock, n):
    lock.acquire()
    print("Hi", n , "from process", current_process().pid)
    lock.release()

def manyGreetings():
    lock1 = Lock()

    print("Hi from process", current_process().pid, "(parent process)")

    for i in range(10):
        Process(target=sayHi4, args=(lock1, "p"+str(i))).start()
        # the above line is the same as the 2 below. 
        # p = Process(target=sayHi3, args=(personName,), name=str(i))
        # p.start()
 
if __name__ == "__main__":
    ### execute
    manyGreetings()