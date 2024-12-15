#Write a Python program that takes a nested dictionary where each key is a person's name, and the value is another dictionary containing their age and city. The program should print out all the names of people who live in "New York' and are over 30 years old.
people = {
    'John': {'age': 45, 'city': 'City 1'},
    'Mike': {'age': 30, 'city': 'NYC'},
    'Sarah': {'age': 32, 'city': 'NYC'},
    'Anna': {'age': 28, 'city': 'City 4'}
}
result=[]
for name,detail in people.items():
    if detail['city']=='NYC' and detail[age] > 30:
        result.append(name)
print(result)
