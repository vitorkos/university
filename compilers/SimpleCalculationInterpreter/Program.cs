using System;

namespace SimpleCalculationInterpreter{
    class Program{
        public static void Main(String[] args){
            Interpreter interpreter = new Interpreter();

            string[] commands = {
                "PRINT 2 + 2 * (2+5+5+5+5+5)",
                "xis = 4+4",
                "PRINT xis"
            };

            foreach (var command in commands)
            {
                interpreter.Execute(command);
            }
        }
    }
}