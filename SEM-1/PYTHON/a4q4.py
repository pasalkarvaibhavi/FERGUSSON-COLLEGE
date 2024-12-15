# skills_A = ('Python', 'Java', 'SQL)
#skills_B = ('Python', 'HTML', 'CSS')
#Write a Python program to find:
#Skills that are in both sets.
#Skills that are unique to skills_A.
#The union of both skill sets.

a={'Python','Java','SQL'}
b={'Python','HTML','CSS'}

print(a.union(b))

print(a.intersection(b))

print(a.difference(b))
