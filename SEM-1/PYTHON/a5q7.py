#Write a Python program that reads a text file and counts how many times each word appears in the file. The program should display the word frequency in descending order.
source = input("Enter Source file:")

with open(source, 'r') as file:
    words = file.read().split()

for word in set(words):
    print(f"{word}:{words.count(word)}")
