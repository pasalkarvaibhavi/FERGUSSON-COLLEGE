##employee_data = ('John', 'Doe', 34, 'Developer', 'New York')
#Write a function to unpack the values of the tuple into separate variables.
#Check if the value 'Developer' is present in the tuple.
#Convert the tuple into a list and add a new element Full-time".#

employee_data = {'John', 'Doe', 34, 'Developer', 'New York'}

print(employee_data)


def unpack_tuple(data):
    fist_name, lastname, age, position, city = data
    return fist_name, lastname, age, position, city


fist_name, lastname, age, position, city = unpack_tuple(employee_data)
print(f"Firstname:{fist_name}, lastname:{lastname},age:{age},Position:{position},City:{city}")

print('Developer' in employee_data)

employee = list(employee_data)

employee.append("Full Time")

print(employee)
