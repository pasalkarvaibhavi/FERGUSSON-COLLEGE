#Create a simple calculator that allows the user to input two numbers and an operator (+, ****//). Based on the operator provided, the program should perform the corresponding arithmetic operation and display the result.

print("SIMPLE CALCULATOR")
a=int(input("Enter first value:"))
b=int(input("Enter second value:"))

ch=input("Enter Operator(+,-,/,*,//,%):")

if ch=="+":
    print("Addition:",a+b)
elif ch=='-':
    print("Subtraction:",a-b)
elif ch=='*':
    print("Multiplication:",a*b)
elif ch=="/":
    print("Division:",a/b)
else:
    print("Enter Right Choice.")
