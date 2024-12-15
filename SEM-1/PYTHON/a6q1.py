#Create a class Car with two attributes: brand and year. Write a method display info() that prints the car's brand and year. Then, create an object of the Car class and call the display info() method to display the car's details. Bonus: Add an attribute for color and include it in the display_info() method!
class Car:
    brand, year = 0, 0

    def Display_info(self, brand, year, color):
        self.brand = brand
        self.year = year
        self.color = color

        print(f"brand:{brand},YEAR:{year},color:{color}")


c = Car()
c.Display_info('Activa', 2009, 'red')
