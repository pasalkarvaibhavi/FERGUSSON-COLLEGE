#Create a Python module with a function that calculates the area of a circle. Import this module in another script and use it to find the area for a radius of 5.
import math

def calculate_area(radius):
    return math.pi*radius**2


import circle_area

print(circle_area.calculate_area(5))
