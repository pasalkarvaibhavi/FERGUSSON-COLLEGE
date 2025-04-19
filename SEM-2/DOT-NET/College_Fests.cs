//Question 4: College Fest Event Handling

using System;

//Event Publisher
class College
{
    public delegate void CollegeFestHandler(int numberOfPeople);
    public event CollegeFestHandler CollegeFest;

    public void PublishEvent(int numberOfPeople)
    {
        if (CollegeFest != null)
        {
            CollegeFest(numberOfPeople);
        }
    }
}

//Event Subscribers
class Decorator
{
    public void HandleEvent(int numberOfPeople)
    {
        double decorationCost = 10000 + (10 * numberOfPeople);
        Console.WriteLine($"Decoration Cost: Rs {decorationCost}");
    }
}

class Caterer
{
    public void HandleEvent(int numberOfPeople)
    {
        double cateringCost = 200 * numberOfPeople;
        Console.WriteLine($"Catering Cost: Rs {cateringCost}");
    }
}

class Program
{
    static void Main()
    {
        College college = new College();
        Decorator decorator = new Decorator();
        Caterer caterer = new Caterer();

        college.CollegeFest += decorator.HandleEvent;
        college.CollegeFest += caterer.HandleEvent;

        Console.Write("Enter the number of people visiting the fest: ");
        int numberOfPeople = int.Parse(Console.ReadLine());

        college.PublishEvent(numberOfPeople);
    }
}
