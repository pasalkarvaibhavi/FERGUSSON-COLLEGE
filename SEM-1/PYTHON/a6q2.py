#Create a class Employee with attributes like name, position, and salary. Use the constructor (init()) to initialize the attributes when an object is created. Write a method to display employee details.
class Employee:
    def __init__(self,name='harry',pos='Manager',sal=10000):
        self.name=name
        self.pos=pos
        self.sal=sal
        print(f"name:{name} ,position:{pos} ,salary:{sal}")
obj=Employee()
obj.name
obj.pos
obj.sal

