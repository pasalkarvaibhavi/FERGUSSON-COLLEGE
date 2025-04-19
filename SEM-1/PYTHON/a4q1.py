#The advanced_operations.py module should contain functions for power and square root.
# Import these modules in a main script and demonstrate their usage.
def pow(a, b):
    print("Power:", a ** b)


def square(a, b):
    print("sqaure of a:", a ** 2)
    print("square of b:", b ** 2)


def add(a, b):
    print("Addiotion:", a + b)


def sub(a, b):
    print("Substraction:", a - b)


def mult(a, b):
    print("Multiplication:", a * b)


def div(a, b):
    print("Division:", a / b)


from basic_operation import *
from advance_operation import *

add(10, 2)
sub(10, 2)
mult(10, 2)
div(10, 2)

square(10, 2)
pow(10, 2)

