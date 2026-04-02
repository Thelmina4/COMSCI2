#!/usr/bin/env python3

# dog.py

class Dog:
    species = "Canis familiaris"

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def bark(self):
        return(f"{self.name} says woof")
    
    def plays_with(self, other):
        return(f"{self.name} plays with {other.name}")
    
class Owner:
    def __init__(self, name, dog):
        self.name = name
        self.dog = dog

    def walk_dog(self):
        return f"{self.name} is walking {self.dog.name}"

dog1 = Dog("Charlie", 6)
dog2 = Dog("Miles", 34)
# print(dog1.species)
# print(dog1.name)
# print(dog1.age)

# print(dog2.bark())
# print(dog1.plays_with(dog2))

thelma = Owner("thelmina", dog1)
print(thelma.walk_dog())

print(thelma.dog.bark())