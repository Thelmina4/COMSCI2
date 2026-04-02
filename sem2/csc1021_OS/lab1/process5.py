from multiprocessing import *
# https://selkie.macalester.edu/csinparallel/modules/ParallelProcessesInPython/build/html/Communication.html

# Execution Order & resource contention

def dig(workerNames, holeID, lock):
    # Each worker attempts to acquire the lock,
    # and is only allowed to print once that acquisition succeeds.
    #  After printing, the worker releases the lock so that another worker may print.
    lock.acquire()
    print("Hiddy-ho!  I'm worker", workerNames , "and today I have to dig hole", holeID)
    lock.release()

def assignDiggers():
    lock = Lock()
    workerNames = ["A", "B", "C", "D", "E", "F", "G"]
    print("Hi from process", current_process().pid, "(parent process)")

    for holeID in range(len(workerNames)):
        Process(target=dig, args=(workerNames[holeID], holeID, lock)).start()
        # the above line is the same as the 2 below. 
        # p = Process(target=sayHi3, args=(personName,), name=str(i))
        # p.start()
    # print("\n", current_process().pid)

    # these 2 functions are the same
    for i in workerNames:
        Process(target=dig, args=(i, workerNames.index(i), lock)).start()
 
if __name__ == "__main__":
    ### execute
    assignDiggers()