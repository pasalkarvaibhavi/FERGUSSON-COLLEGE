#Create a function that rounds a list of numbers to the nearest whole number.
def round_to_whole_number(number):
    return tuple(map(lambda x:round(x),number))

number=[1.2,2.6,3.9]
print(round_to_whole_number(number))



