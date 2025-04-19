#Create a function that imports datetime and returns the current date and time.

#Example: current_datetime() should return the current timestamp like "2023-09-14

import datetime

c_datetime=datetime.datetime.now()
print(c_datetime)

c_year=datetime.datetime.now().year
print(c_year)

c_month=datetime.datetime.now().month
print(c_month)

c_week_number=datetime.datetime.now().strftime("%U")
print(c_week_number)

c_week_day=datetime.datetime.now().strftime("%A")
print(c_week_day)

day_of_the_year=datetime.datetime.now().strftime("%j")
print(day_of_the_year)

day_month=datetime.datetime.now().day
print(day_month)
