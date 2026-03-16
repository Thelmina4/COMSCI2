#!/usr/bin/env python3

# Triangle3D.py

# Use the Dot3D class to create
# a Triangle3D class representing a triangle in 3D space.
# defined by three vertices (dots) in a three-dimensional space.
#
# - Perimeter: The sum of the lengths of the triangle’s edges
#   - perimeter = edge1 + edge2 + edge3
#   -  edge1, edge2, and edge3 are the distances between the triangle’s vertices.
#
# - Area: Calculated using Heron’s formula

#   s = (edge1 + edge2 + edge3) / 2
#   area = √(s * (s - edge1) * (s - edge2) * (s - edge3))

# Requirements
# Create a class called Triangle3D.

# The class should take three Dot3D objects as parameters,
# representing the triangle’s vertices.

# Implement the following methods:

# calculate_perimeter(self): 
# Compute and return the perimeter of the triangle.

# calculate_area(self): 
# Compute and return the area of the triangle using Heron’s formula.
class Dot3D:
    def __init__(self, x, y, z, label=None):
        self.x = x
        self.y = y
        self.z = z
        self.label = None if label is None else label
        

    def distance_to(self, other):
        distance = (((other.x - self.x)**2) +
                    ((other.y - self.y)**2) +
                    ((other.z - self.z)**2)
                    )
        # print((other.x - self.x)**2 + ((other.y - self.y)**2) )
        return f"{distance**(1/2)}"

    def add_vector(self, other):
        x = self.x+other.x
        y = self.y+other.y
        z = self.z+other.z
        label = self.label + "+" + other.label
        # print(x, y, z, label)
        resultant_dot = Dot3D(x, y, z, label)

        return resultant_dot
    
class Triangle3D:
    def __init__(self, dot1, dot2, dot3):
        self.dot1 = dot1
        self.dot2 = dot2
        self.dot3 = dot3

    def calculate_perimeter(self):
        self.edge1 = self.dot1.distance_to(self.dot2)
        self.edge2 = self.dot2.distance_to(self.dot3)
        self.edge3 = self.dot3.distance_to(self.dot1)
        return float(self.edge1) + float(self.edge2) + float(self.edge3)

    def calculate_area(self):
        s = self.calculate_perimeter() /2
        area = (s * (s - float(self.edge1)) * (s - float(self.edge2)) * (s - float(self.edge3)))
        return area ** (1/2)   

if __name__ == "__main__":
    dot1 = Dot3D(0, 0, 0)
    dot2 = Dot3D(3, 0, 0)
    dot3 = Dot3D(0, 4, 0)
    triangle = Triangle3D(dot1, dot2, dot3)

    perimeter = triangle.calculate_perimeter()
    print(perimeter)
    area = triangle.calculate_area()
    print(area)
