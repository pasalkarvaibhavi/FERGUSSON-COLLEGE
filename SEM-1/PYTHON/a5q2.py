#Write a Python program that uses a lambda function to sort a list of tuples based on the second element of each tuple.
fruits=[(2,'banana'),(3,'apple'),(1,'orange')]
sorted_fruits= sorted(fruits,key=lambda x:x[1])
print(sorted_fruits)
