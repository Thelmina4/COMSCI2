#!/usr/bin/env python3

# Author: Thelma Clarke
# SID: 19746069
# Week 1 Lab Exercises

# question 1
# q1_sum = ([
#     [1, 0, 2],
#     [5, 5, 7],
#     [9, 4, 3]
# ])
# print(sum(q1_sum[0]))
def sum_even(file_name):
   total = 0

   for line in file_name:
      # print(line)
      for i in line:
         # print(i)
         if i % 2 == 0:
            total += i
   print(total)

# sum_even(q1_sum)

# question 2
# sentence = "This is DCU!"
def move_vow(line):
   vowels = "aeiouAEIOU"
   line = [i for i in line]
   # print(line)
   vow = []
   cons = []
   for i in line:
      if i in vowels:
         vow.append(i)
      else:
         cons.append(i)
   # faster & better for time complexity if I
   # append the vowel to a list
   # and popped the offending vowel from the sentence?
   # should I then clear the original sentence?
   string_again = "".join(vow) + "".join(cons)
   print(string_again)

# move_vow(sentence)

# question 3
class Memories(object):
   def __init__(self, **kwargs):
      for k, v in kwargs.items():
         setattr(self, k, v)

      # self.attributes = kwargs

   def remember(self, attribute):
      if hasattr(self, attribute):
         return getattr(self, attribute)
      else:
         return False

# return self.attributes.get(attribute, False)

# question 4

class Test(object):
   def __init__(self, subject_name, correct_answers, pasing_mark):
      self.subject_name = subject_name
      self.correct_answers = correct_answers
      self.pasing_mark = str(float(pasing_mark[:-1]) / 100)
      # print(self.pasing_mark)

class Student(Test):
   def __init__(self, name):
      self.name = name

   def take_test(self, paper, usr_ans):
      # paper.correct_ans = list
      # usr_ans = list
      # num of ans
      no_ans = len(paper.correct_answers)
      # lets say the no of ans is 5, passing grade is 70
      # need 4 correct ans
      # weight per q is len/ans
      weight = 1 / no_ans
      # print(no_ans, weight)
      correct = 0
      for i in usr_ans:
         # print(i)
         if i in paper.correct_answers:
            correct += 1
      # print(correct, self.name)

      grade = str(correct * weight * 100) + "%"
      # print(grade)
      # print((correct * weight), float(paper.pasing_mark))
      output = []
      if correct * weight >= float(paper.pasing_mark):
         print(self.name, "passed the", paper.subject_name, "test with the score of", grade)
      else:
         print(self.name, "failed the", paper.subject_name, "test!")

# question 5

def histogram(numbers, line):
   for i in numbers:
      print(i * str(line))

# numbers = [6, 2, 15, 3, 20, 5]
# line = “=”
# histogram(numbers, line)

# question 6

def filter_star(chocolates, stars):
   result = {}
   for name, rating in chocolates.items():
      if len(rating) == stars:
         result[name] = rating
   if result:
      print(result)
   else:
      print("No result found!")

if __name__ == "__main__":
   # question 1
   q1_sum = ([
       [1, 0, 2],
       [5, 5, 7],
       [9, 4, 3]
   ])
   # print(sum(q1_sum[0]))
   sum_even(q1_sum)

   # question 2
   sentence = "This is DCU!"
   move_vow(sentence)

   # question 3
   person1 = Memories(name='Tom', age=32, salary=50000)
   print(person1.remember('salary'))
   print(person1.remember('email'))

   # question 4
   paper1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
   paper2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
   paper3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')

   stu1 = Student('Tom')
   stu1.take_test(paper2, ['1C', '2C', '3D', '4A']) # ➞ Tom passed the Chemistry test with the score 100.0%

   stu2 = Student('John')
   stu2.take_test(paper1, ['1B', '2C', '3A', '4A', '5B']) # ➞ John failed the Maths test!

   # question 5
   numbers = [6, 2, 15, 3, 20, 5]
   line = '='
   histogram(numbers, line)

   # question 6
   # make a dict w chocolates & their ratings
   chocolates = {
    'Luxury Chocolates': '*****',
    'Tasty Chocolates': '****',
    'Big Chocolates': '*****',
    'Generic Chocolates': '***'
   }
   # if this was supposed to run with the print outside the function
   # then I would replace return with print(result) else return "No result found!"
   # the next line would then be without the print
   filter_star(chocolates, 3) # 1 x 3 star
   filter_star(chocolates, 2) # no 2 stars
   filter_star(chocolates, 6) # out of bounds of the 5 star rating
   filter_star(chocolates, 5) # 2 x 5 stars
