//Q.1

using System;

class Program
{
    static void Main()
    {
        //Q.1 a)

        Console.Write("Please Enter a String:");
        string input =Console.ReadLine();

        if(input.Length<2)
        {
            Console.WriteLine("String must have at least two characters.");
            return;
        }

        char[] charArray = input.ToCharArray();
        char temp =charArray[0];
        charArray[0] = charArray[charArray.Length - 1];
        charArray[charArray.Length-1]=temp;

        string newString=new string(charArray);
        Console.WriteLine("New String: " + newString);
    }
    

}