# Define a class Animal with a method speak(), which prints a generic message like "Animal sound". Then create subclasses Dog and Cat that override the speak() method with their respective sounds.
class Animal:
    def speak(self):
        print("Animal sound")

class Dog(Animal):
    def speak(self):
        print("Woof!")

class Cat(Animal):
    def speak(self):
        print("Meow!")

dog = Dog()
cat = Cat()

dog.speak()
cat.speak()