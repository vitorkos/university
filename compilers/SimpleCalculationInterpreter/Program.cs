using System;

namespace SimpleCalculationInterpreter
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] inputLines = {
                "PRINT 2 + 2 * (2+5+5+5+5+5)",
                "xis = 4+4",
                "PRINT xis"
            };

            Interpreter interpreter = new Interpreter();
            foreach (string line in inputLines)
            {
                try
                {
                    interpreter.Execute(line);
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
        }
    }
}
