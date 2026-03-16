#!/usr/bin/env python3

def q1_sum(numbers):
    total = 0
    for i in numbers:
        for x in i:
            if x %2 ==0:
                total += x
    return total

def move_vow(line):
    vow = []
    for i in line:
        print(i)
        if i in "aeoiuAEIOU":
            vow.append(i)
            line = line.replace(i, "", 1)
    return "".join(vow) + line

class Memories():
    def __init__(self, name , age, salary):
        self.age = age
        self.name = name
        self.salary = salary

    def remember(self, input):
        x = list(age, name, salary)
        if input in x:
            return self.input
        
# nums =  [[1, 0, 2], [5, 5, 7], [9, 4, 3]]
# print(q1_sum(nums))
# line = "This is DCU!"
# print(move_vow(line))

# j = Memories("tom", 32, 500)
# print(j.remember("email"))

def sum_q1(n):
    if n == 1:
        return 1
    return n + sum_q1(n-1)

print(sum_q1(6))

def rev(n):
    if n  == 0:
        return 0
    
    return (n%10) * (10**(len(str(n)) - 1)) + rev(n//10)

n = 123
print(rev(n))

def rev_str(line):
    if line == "":
        return ""
    
    return line[-1] + rev_str(line[:-1])

print(rev_str("hello"))

def inverse_list(x):
    if x == []:
        return []
    
    for i in x:
        return [x[-1]] + inverse_list(x[:-1]) 
    
print(inverse_list([1, 2, 3, 4]))

def multiply(x, y):
    if y == 0:
        return 0
    if x < 0 and y < 0:
        return multiply(-x, -y)
    elif y < 0:
        return multiply(x, -y)
    return x + multiply(x, y-1)

print(multiply(10, 2))
print(multiply(-51, -4))
# print(multiply(10, 2))
# z = -4
# z = -z
# print(z)
