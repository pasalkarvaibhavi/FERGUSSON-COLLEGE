#Use round() inside map() to round a list of floating-point numbers to 1 decimal place.
def round_to_one(numbers):
    return tuple(map(lambda x:round(x,1),numbers))

numbers=[12.34,3.454,4.455]
print(round_to_one(numbers))