//Without Recursion

using System;
using System.Runtime.InteropServices;
class Program
{
    static void Main()
    {
        Console.Write("Enter a number: ");
        int number = int.Parse(Console.ReadLine());
        int originalNumber = number;
        int reversedNumber = 0;

        while (number != 0)
        {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }

        if (originalNumber == reversedNumber)
        {
            Console.WriteLine("The number is a palindrome.");
        }
        else
        {
            Console.WriteLine("The number is not a palindrome.");
        }
    }
}

//With Recursion

//using System;
//class Program
//{
//    static void Main()
//    {
//        Console.Write("Enter a number: ");
//        int number = int.Parse(Console.ReadLine());
//        int reversedNumber = ReverseNumber(number, 0);

//        if (number == reversedNumber)
//        {
//            Console.WriteLine("The number is a palindrome.");
//        }
//        else
//        {
//            Console.WriteLine("The number is not a palindrome.");
//        }
//    }

//    static int ReverseNumber(int number, int reversedNumber)
//    {
//        if (number == 0)
//            return reversedNumber;

//        int digit = number % 10;
//        reversedNumber = reversedNumber * 10 + digit;

//        return ReverseNumber(number / 10, reversedNumber);
//    }
//}

//Question_2 : Calculate Square Root with Exception Handling


//using System;

//class Program
//{
//    static void Main()
//    {
//        try
//        {
//            Console.Write("Enter a number: ");
//            double number = double.Parse(Console.ReadLine());

//            if (number < 0)
//            {
//                throw new ArgumentException("Number cannot be negative.");
//            }

//            double squareRoot = Math.Sqrt(number);
//            Console.WriteLine($"The square root of {number} is {squareRoot}");
//        }
//        catch (ArgumentException ex)
//        {
//            Console.WriteLine(ex.Message);
//        }
//        catch (FormatException)
//        {
//            Console.WriteLine("Invalid input. Please enter a valid number.");
//        }
//    }
//}




