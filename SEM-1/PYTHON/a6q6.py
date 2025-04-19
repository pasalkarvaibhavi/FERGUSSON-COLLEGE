#Define two classes, Engine and Body, with constructors that initialize respective attributes like horsepower and material. Then, create a class Car that inherits from both Engine and Body. Use the super() method to initialize both parent class attributes from the Car class.
class Engine:
    def __init__(self,Horsepower=0):#,material='Polyster'):
        self.Horsepower=Horsepower
        print(f"Horsepower:{Horsepower} ")
class Body:
    def __init__(self,material=0):
        self.material=material
        print(f"material:{material}")

class Car(Engine,Body):
    def __init__(self,milege=0):
         self.milege=milege
         super().__init__('900w')
         Body.__init__(self,'silicon')
         print(f"milege:{milege}")

obj=Car(90)
obj.milege
