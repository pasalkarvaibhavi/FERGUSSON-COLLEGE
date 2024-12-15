#Write a Python program that counts the number of vowels in a given string. Ignore case sensitivity.
def count(s):
    v="AEIOUaeiou"
    count=0
    for char in s:
        if char in v:
            count=count+1
    return count
s=input("Enter String:")
print(count(s))

