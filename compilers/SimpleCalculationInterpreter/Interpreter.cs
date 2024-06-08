using System;
using System.Collections.Generic;

namespace SimpleCalculationInterpreter
{
    public class Interpreter{
        private SymbolTable _symbolTable;

        public Interpreter(){
            _symbolTable = new SymbolTable();
        }

        public void Execute(string command){
            Lexer lexer = new Lexer(command);
            List<Token> tokens = lexer.GetTokens();

            Parser parser = new Parser(tokens);
            dynamic result = parser.Parse();

            if (result.Command == "PRINT"){
                dynamic value = result.Value;
                if (value is string){
                    Console.WriteLine(_symbolTable.Get(value));
                }
                else{
                    Console.WriteLine(value);
                }
            }
            else if (result.Command == "ASSIGN"){
                string varName = result.Variable;
                dynamic value = result.Value;
                if (value is string){
                    _symbolTable.Set(varName, _symbolTable.Get(value));
                }
                else{
                    _symbolTable.Set(varName, value);
                }
            }
        }
    }
}