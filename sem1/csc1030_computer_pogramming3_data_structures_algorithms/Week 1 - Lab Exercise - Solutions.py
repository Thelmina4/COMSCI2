def q1_sum(nested_list):

    total = 0
    for l in nested_list:
        for x in l:

            if x % 2 == 0:
                total += x

    return total

res = q1_sum([
    [1, 0, 2],
    [5, 5, 7],
    [9, 4, 3]
])

nested_list = [
    [1, 0, 2],
    [5, 5, 7],
    [9, 4, 3]
]

res = [x for l in nested_list for x in l if x % 2 == 0]

print(sum(res))

##########################################################

def move_vow(str_input):

    vowels = [x for x in str_input if x in 'aeiouAEIOU']
    consonants = [x for x in str_input if not x in 'aeiouAEIOU']

    return [', '.join([x for x in vowels if x.strip()]),
            ', '.join([x for x in consonants if x.strip()])]

res = move_vow('This is DCU!')

print(f"{res[0]} - {res[1]}")

########################################################

class Memories:

    def __init__(self, **kwargs):

        for k, v in kwargs.items():

            setattr(self, k, v)

    def remember(self, param):

        if hasattr(self, param):
            return getattr(self, param)

        return False

person1 = Memories(name='Tom', age=32, salary=50000)
print(person1.remember('salary'))
print(person1.remember('email'))

#####################################################

class Test:

    def __init__(self, subject_name, correct_answers, passing_mark):

        self.subject_name = subject_name
        self.correct_answers =  correct_answers
        self.passing_mark = passing_mark

paper1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
paper2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
paper3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')

class Student:
    def __init__(self, name):
        self.name = name

    def take_test(self, paper, answers):

        num_correct = 0
        passing_mark = int(paper.passing_mark[:2])

        passed_or_failed = 'failed'

        for i in range(len(paper.correct_answers)):

            if paper.correct_answers[i] == answers[i]:
                num_correct += 1

        percentage_correct = (num_correct * 100) / len(paper.correct_answers)

        if percentage_correct >= passing_mark:
            passed_or_failed = 'passed'

        return f"{self.name} {passed_or_failed} the {paper.subject_name} test with the score {percentage_correct}%"

stu1 = Student('Tom')
print(stu1.take_test(paper2, ['1C', '2C', '3D', '4A'])) #➞ Tom passed the Chemistry test with the score 100.0%

stu2 = Student('John')
print(stu2.take_test(paper1, ['1B', '2C', '3A', '4A', '5B'])) #➞ John failed the Maths test!

#######################################################

class Student:
    def __init__(self, name):
        self.name = name

    def take_test(self, paper, answers):

        num_correct = 0
        passing_mark = int(paper.passing_mark[:2])

        passed_or_failed = 'failed'

        ans_dict = {s[0]: s[1] for s in answers}
        correct_answer_dict = {s[0]: s[1] for s in paper.correct_answers}

        for k, v in ans_dict.items():

            if correct_answer_dict[k] == v:
                num_correct += 1

        percentage_correct = (num_correct * 100) / len(paper.correct_answers)

        if percentage_correct >= passing_mark:
            passed_or_failed = 'passed'

        return f"{self.name} {passed_or_failed} the {paper.subject_name} test with the score {percentage_correct}%"

stu1 = Student('Tom')
print(stu1.take_test(paper2, ['1C', '2C', '3D', '4A'])) #➞ Tom passed the Chemistry test with the score 100.0%

stu2 = Student('John')
print(stu2.take_test(paper1, ['1B', '2C', '3A', '4A', '5B'])) #➞ John failed the Maths test!

#########################################################################

def histogram(list_input, char_input):

    for x in list_input:
        for y in range(x):
            print(char_input, end="")
        print()

histogram([6, 2, 15 , 3, 20 , 5], '=' )

#########################################################################

def histogram(list_input, char_input):

    outer_list = []
    for x in list_input:
        tmp_nested_list = []
        for y in range(x):
            tmp_nested_list.append(char_input)
        outer_list.append(tmp_nested_list)

    for l in outer_list:
        print(''.join(x for x in l))

print("--------------------------------")
histogram([6, 2, 15 , 3, 20 , 5], '=' )

#############################################################
def filter_star(input_dict, num):

    for k, v in input_dict.items():
        if len(v) == num:
            return {k, v}

    return "No result found!"

print(filter_star({
  'Luxury Chocolates': '*****',
  'Tasty Chocolates': '****',
  'Big Chocolates': '*****',
  'Generic Chocolates': '***'
}, 4))

print(filter_star({
  'Luxury Chocolates': '*****',
  'Tasty Chocolates': '****',
  'Big Chocolates': '*****',
  'Generic Chocolates': '***'
}, 2) )