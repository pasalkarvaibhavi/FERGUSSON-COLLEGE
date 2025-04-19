# Write a function that imports your custom module (e.g.. math_utils.py) and uses a function from it to calculate the factorial of a number.
def fact(n):
    if n==0 or n==1:
        return 1
    else:
        return n*fact(n-1)

#main
import math_util
x=int(input("enter number:"))
print(math_util.fact(x))
