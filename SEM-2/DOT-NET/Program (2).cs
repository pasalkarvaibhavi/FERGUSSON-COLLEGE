using System;
using MyOperationsLibrary; // Import the custom library

class Program
{
    static void Main()
    {
        MyOperations ops = new MyOperations();

        try
        {
            Console.WriteLine("Trying division...");
            ops.Divide(10, 0); // This will throw a custom exception
        }
        catch (MyCustomException ex)
        {
            Console.WriteLine($"Error Code: {ex.ErrorCode}, Message: {ex.Message}");
        }

        try
        {
            Console.WriteLine("\nTrying array access...");
            ops.AccessArray(); // This will throw a custom exception
        }
        catch (MyCustomException ex)
        {
            Console.WriteLine($"Error Code: {ex.ErrorCode}, Message: {ex.Message}");
        }
    }
}
