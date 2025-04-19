#Write a Python function multiply(a, args) that multiplies a fixed argument a with a variable number of additional arguments. Return the product.
def multiply(product1,*args):
    product=1
    for i in args:
        product=product*i
    return product
s=input("Enter Number:")

number=map(int,s.split())
print(multiply(*number))
