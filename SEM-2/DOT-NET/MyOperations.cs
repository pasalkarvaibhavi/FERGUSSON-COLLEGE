using System;

namespace MyOperationsLibrary
{
    public class MyCustomException : Exception
    {
        public int ErrorCode { get; set; }

        public MyCustomException(string message, int errorCode) : base(message)
        {
            ErrorCode = errorCode;
        }
    }

    public class MyOperations
    {
        public void Divide(int a, int b)
        {
            try
            {
                if (b == 0)
                    throw new DivideByZeroException();

                Console.WriteLine($"Result: {a / b}");
            }
            catch (DivideByZeroException)
            {
                throw new MyCustomException("Cannot divide by zero.", 1001);
            }
        }

        public void AccessArray()
        {
            try
            {
                int[] arr = { 1, 2, 3 };
                Console.WriteLine(arr[5]); // Out of bounds
            }
            catch (IndexOutOfRangeException)
            {
                throw new MyCustomException("Array index is out of range.", 1002);
            }
        }
    }
}
