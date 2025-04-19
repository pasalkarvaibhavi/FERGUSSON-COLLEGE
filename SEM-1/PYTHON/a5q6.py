#Write a Python program that:
#Asks the user for the name of a source file (e.g., source.txt) and a destination file
#(e.g., destination.txt).
#Copies the content of the source file to the destination file.


source=input("Enter Source file:")
destination=input("Enter destination file:")

open(destination,'w').write(open(source,'r').read())
