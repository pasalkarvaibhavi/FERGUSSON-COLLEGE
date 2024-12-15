#Write a Python program that takes the principal amount, rate of interest, and time period as inputs and calculates the simple interest. Display the calculated interest.
p=float(input("Enter Principle amount:"))
r=float(input("Enter rate of interest:"))
t=float(input("Enter Time:"))
s=(p*r*t)/100
print("Simple Interest:",s)
