# Q1
class Queue:

    def __init__(self):
        self.lst = []

    def enqueue(self, val):
        self.lst.append(val)

    def dequeue(self):
        return self.lst.pop(0)

    def first(self):
        return self.lst[0]

    def is_empty(self):
        return len(self.lst) == 0

    def size(self):
        return len(self.lst)

    def __str__(self):
        return "Front -> " + " | ".join(str(x) for x in self.lst) + " <- Back"

    def reverse(self):
        if self.is_empty():
            return
        front = self.dequeue()
        self.reverse()
        self.enqueue(front)

    def find_minimum(self):
        if self.is_empty():
            return None

        x = self.dequeue()

        if self.is_empty():
            self.enqueue(x)
            return x

        m = self.min()

        self.enqueue(x)

        return x if x < m else m

    def min_alternative(self, min_val=None):
        if self.is_empty():
            return

        if min_val is None:
            first_val = self.dequeue()
            min_val = [first_val]
        else:
            first_val = None

        current_val = self.dequeue()
        self.min(min_val)

        if current_val < min_val[0]:
            min_val[0] = current_val

        self.enqueue(current_val)
        if first_val is not None:
            self.enqueue(first_val)

        return min_val[0]

q = Queue()
for x in [4, 1, 3, 2]:
    q.enqueue(x)

print("Original:", q)

q.reverse()
print("Reversed:", q)

print("Min:", q.find_minimum())

# Q2
def generate_binary_numbers(n):
    # Initialize a queue with the binary number '1'
    q = Queue()
    q.enqueue('1')

    # List to store the binary numbers
    result = []

    # Generate n binary numbers
    for _ in range(n):
        # Dequeue the front binary number and print it
        curr = q.dequeue()
        result.append(curr)

        # Enqueue the next two binary numbers
        q.enqueue(curr + '0')
        q.enqueue(curr + '1')

    return result

n = 16
binary_sequence = generate_binary_numbers(n)
print(' '.join(binary_sequence))

# Q3
class Stack:
    '''Python implementation the stack'''

    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def top(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)

s = Stack()
output = []
str_input = 'EAS*Y*QUE***ST***IO*N***'
for i in str_input:
    if i not in '*':
        s.push(i)
    else:
        output.append(s.pop())

print('\n' + str(output))

# Q4
q = Queue()
output = []
str_input = 'EAS*Y*QUE***ST***IO*N***'
for i in str_input:
    if i not in '*':
        q.enqueue(i)
    else:
        output.append(q.dequeue())

print('\n' + str(output))

# Q5
def reverse(string_input):
    n = len(string_input)
    stack = Stack()

    for i in range(0, n, 1):
        stack.push(string_input[i])
    string_output = ""

    for i in range(0, n, 1):
        string_output += stack.pop()

    return string_output

str_input = "Hello DCU!"
str_output = reverse(str_input)
print("\nReversed string is: " + str_output)

# Q6: this is a solution for single digit formula
def evaluate_postfix(formula):
    OPERATORS = set(['+', '-', '*', '/', '(', ')', '^'])
    stack = Stack()
    for ch in formula:
        if ch not in OPERATORS:
            stack.push(float(ch))
        else:
            b = stack.pop()
            a = stack.pop()
            c = {'+': a + b, '-': a - b, '*': a * b, '/': a / b, '^': a ** b}[ch]
            stack.push(c)
    return stack.pop()

exp = "1432^*+147--+"
obj = evaluate_postfix(exp)
print("\nPostfix evaluation: %d" % obj)

# Q7
class Deque:

    def __init__(self):
        self.lst = []

    def add_last(self, val):
        self.lst.append(val)

    def add_first(self, val):
        self.lst.insert(0, val)

    def first(self):
        return self.lst.pop(0)

    def last(self):
        return self.lst.pop()

    def is_empty(self):
        return len(self.lst) == 0

def palindrome(str='Navan'):

    deque = Deque()

    for s in str:
        deque.add_last(s)

    while not deque.is_empty():

        first = deque.first()

        if not deque.is_empty():
            last = deque.last()

            if last != first:
                return False

    return True
