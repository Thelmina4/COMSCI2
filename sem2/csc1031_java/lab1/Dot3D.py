#!/usr/bin/env python3
# filename: Dot3D.py

# Create a Python class to represent a dot in 3D space.
# Implement methods to calculate the 
# distance between two dots and to add two vectors, 
# resulting in a new dot.

# distance = √((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
# distance_to(self, other):
# Calculate the Euclidean distance between the current dot and another dot.
# Return the computed distance.

# add_vector(self, other):
# Add the current dot’s coordinates to another dot’s coordinates
# (vector addition) and return a new Dot3D instance with the resulting coordinates
# and label containg both intial labels with + sign
# (for example, "A+B" where "A" and "B" - are the original labels).

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

if __name__ == "__main__":
    dot1 = Dot3D(1, 2, 3, "x1")
    dot2 = Dot3D(4, 5, 6, "x2")

    # # (4-1)**2 = 9
    dist = dot1.distance_to(dot2)
    print(dist)
    # print(dot1.distance_to(dot2))
    # print(dot1.add_vector(dot2))

    dot3 = dot1.add_vector(dot2)
    print(dot3)
