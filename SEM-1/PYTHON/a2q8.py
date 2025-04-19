#Write a Python program to take a list of 10 elements and slice it to create a sublist containing every second element.
elements= list(map(int,input("Enter List of 10 eleemtns:").split()))

if(len(elements)!=10):
    print("Please enter exactylr 10 elements.")
else:
    sublist=elements[1::2]
    print(sublist)
