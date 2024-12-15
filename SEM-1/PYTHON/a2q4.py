#Create a function print details that accepts keyword arguments and prints them in the format: "key: value". Test the function with different sets of keyword arguments.
def print_details(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}:{value}")


print_details(name="GINNI", age=20)
