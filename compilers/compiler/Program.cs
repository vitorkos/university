namespace Calc
{
    class CalcInt{
        public static void Main(String[] args){
            var interpreter = new Interpreter();
            Console.WriteLine("Calc Intepreter");
            String? command = null;
            do{
                Console.WriteLine(">");
                command = console.ReadLine();
                String output = interpreter.Exec(command);
                Console.WriteLine(output);

            }while(!String.IsNullOrEmpty(command));
        }
    }
}