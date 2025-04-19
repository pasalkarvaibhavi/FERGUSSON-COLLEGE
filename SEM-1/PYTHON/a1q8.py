#Write a Python program that converts temperature from Celsius to Fahrenheit and vice versa. The program should ask the user for the temperature value and the unit (Celsius or Fahrenheit) and then perform the conversion.
temp=int(input("Enter Temperature value:"))
unit=input("Enter Unit(f/c):")

if(unit=="f"):
    f=(temp*(9/5))+32
    print("Temperature in Fahrenheit:",f)
elif(unit=="c"):
    c=(temp-32)*(5/9)
    print("Temperature in Celsius:",c)
else:
    print("Please Choose right Value")
