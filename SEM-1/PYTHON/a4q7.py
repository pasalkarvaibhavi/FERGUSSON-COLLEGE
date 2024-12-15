#Write a Python program that removes the duplicate values from the list using a set.
#Convert the set back into a list. List=> numbers = [1, 2, 2, 3, 4, 4, 5]
duplicate_list = [1,2,2,3,4,4,5]
make_set = set(duplicate_list)
list = list(make_set)
print(list)