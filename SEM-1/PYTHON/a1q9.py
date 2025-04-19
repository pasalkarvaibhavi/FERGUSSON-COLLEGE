#Write a Python program that calculates the Body Mass Index (BMI) based on user input for weight (in kg) and height (in meters). The formula for BMI is weight / (height 2). Display the BMI and categorize it as underweight, normal weight, overweight, or obese.
print("BMI CALCULATOR")
height=int(input("Enter height in meters:"))
weight=int(input("Enter weight in kg:"))
bmi=weight/(height**2)

print("BMI:",bmi)

if(bmi<18.5):
    print("Underweight")
elif(18.5<bmi<24.9):
    print("Normal")
elif(25<bmi<29.9):
    print("Overweigth")
else:
    print("Obesity.")
