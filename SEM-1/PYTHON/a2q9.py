#Create a dictionary with at least 5 key-value pairs. Write a Python program to:. Add a new key-value pair to the dictionary.Update an existing key with a new value.
# Delete a key-value pair from the dictionary.

dict={
    "name":"Neha",
    "age":10,
    "city":"Pune",
    "class":"MBA",
    "grade":"O"}

print(dict)

dict["color"]="blue"
print(dict)

dict["age"]=34
print(dict)

del dict["age"]
print(dict)
