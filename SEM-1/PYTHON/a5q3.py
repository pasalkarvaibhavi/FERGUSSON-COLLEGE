#write a menu driven program for file handling on functions like, open, write, read, writeline, readline, close, rename
print("Menu Driven : File Operation")
import os


def menu():
    print("1.Open")
    print("2.Write")
    print("3.Read")
    print("4.Writeline")
    print("5.ReadLine")
    print("6.Close")
    print("7.Rename")
    print("8.Exit")


while (True):
    menu()

    ch = int(input("Enter choice:"))

    f = open("zofi.txt", "a+")

    if (ch == 1):
        f = open("zofi.txt", "a+")

    elif (ch == 2):
        s = input("Enter data you want to write in file:")
        f.write(s)

    elif (ch == 3):
        print(f.read())

    elif (ch == 4):
        s = input("Enter data you want to write in file:")
        f.writelines(s)

    elif (ch == 5):
        print(f.readline())

    elif (ch == 6):
        f.close()

    elif (ch == 7):
        f.close()
        s = input("Enter name for file:")
        os.rename("NewFile.txt", s)

    elif (ch == 8):
        exit(0)
