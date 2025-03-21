//Question 5: OOPS Concepts(Virtual, Override, New, Interface)

using System;

// Interface
interface IEmployee
{
    void Display();
}

// Base Class
class Employee : IEmployee
{
    public string Name { get; set; }
    public int Id { get; set; }

    public Employee(string name, int id)
    {
        Name = name;
        Id = id;
    }

    // Virtual method
    public virtual void Display()
    {
        Console.WriteLine($"Employee Name: {Name}, ID: {Id}");
    }
}

// Derived Class
class Manager : Employee
{
    public string Department { get; set; }

    public Manager(string name, int id, string department) : base(name, id)
    {
        Department = department;
    }

    // Override method
    public override void Display()
    {
        Console.WriteLine($"Manager Name: {Name}, ID: {Id}, Department: {Department}");
    }
}

// Another Derived Class
class Developer : Employee
{
    public string Technology { get; set; }

    public Developer(string name, int id, string technology) : base(name, id)
    {
        Technology = technology;
    }

    // New method (hides the base class method)
    public new void Display()
    {
        Console.WriteLine($"Developer Name: {Name}, ID: {Id}, Technology: {Technology}");
    }
}

class Program
{
    static void Main()
    {
        Employee emp = new Employee("John", 101);
        Manager mgr = new Manager("Alice", 102, "HR");
        Developer dev = new Developer("Bob", 103, "C#");

        emp.Display(); // Calls base class method
        mgr.Display(); // Calls overridden method
        dev.Display(); // Calls new method in Developer class

        // Using interface reference
        IEmployee iemp = new Employee("Charlie", 104);
        iemp.Display(); // Calls base class method
    }
}