#Write a Python program that:
#Reads the content of a file named input.txt.
#Writes the reversed content to another file named reversed.txt.

content=open("input.txt",'r').read()
open("reversed.txt",'w').write(content[::-1])
