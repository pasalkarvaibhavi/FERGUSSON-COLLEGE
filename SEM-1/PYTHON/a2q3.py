#Write a Python function sum_numbers that takes a variable number of arguments and returns their sum. Test the function with different numbers of arguments.
def sum_numbers(*args):
    sum=0
    for i in args:
        sum=sum+i
    print(sum)

s=input("enter Number separated by spaces:")
number=map(int,s.split())
sum_numbers(*number)

