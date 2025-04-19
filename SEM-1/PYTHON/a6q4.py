#Create a class Vehicle with attributes brand and speed. Add a method show_details() to display these details. Then, create a subclass Car that inherits. from Vehicle and adds an attribute mileage. Use the super() method to call the show_details() of the parent class inside the Car class's show_details() method.

class Vehicle:
    brand, speed,color = 0, 0,0
    def Show_Details(self, brand,speed, color,):
        self.brand = brand
        self.speed= speed
        self.color = color
        print(f"brand:{brand},speed:{speed},color:{color}")
class Car(Vehicle):
    milege=0
    def car_type(self,milege):
        self.milege=milege
        super().Show_Details('Honda',2002,'red')
        print(f"milege:{milege}")

obj=Car()
obj.car_type('70kmph')
#obj.Show_Details()
