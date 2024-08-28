namespace Calc {
    class CalcInt{

        public static void Main(String[] args){

            var interpreter = new Interpreter();
            Console.Beep();
            Console.WriteLine("Calc Interpreter");
            string? command = "";
            do {
                Console.Write(">");
                command = Console.ReadLine();
                String output  = interpreter.Exec(command);
                Console.WriteLine(output);
            } while (!String.IsNullOrEmpty(command));
        }

    }


}