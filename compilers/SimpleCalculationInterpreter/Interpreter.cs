using System;

namespace SimpleCalculationInterpreter
{
    public class Interpreter
    {
        private SymbolTable _symbolTable = new SymbolTable();

        public void Execute(string input)
        {
            Lexer lexer = new Lexer(input);
            Parser parser = new Parser(lexer);
            Node tree = parser.Parse();
            Evaluate(tree);
        }

        private int Evaluate(Node node)
        {
            switch (node)
            {
                case NumNode numNode:
                    return numNode.Value;
                case VarNode varNode:
                    return _symbolTable.Get(varNode.Name);
                case AssignNode assignNode:
                    var value = Evaluate(assignNode.Value);
                    _symbolTable.Set(assignNode.Variable.Name, value);
                    return value;
                case BinOpNode binOpNode:
                    var left = Evaluate(binOpNode.Left);
                    var right = Evaluate(binOpNode.Right);
                    switch (binOpNode.Op.Type)
                    {
                        case TokenType.SUM:
                            return left + right;
                        case TokenType.SUB:
                            return left - right;
                        case TokenType.MUL:
                            return left * right;
                        case TokenType.DIV:
                            return left / right;
                    }
                    break;
                case PrintNode printNode:
                    var result = Evaluate(printNode.Expression);
                    Console.WriteLine(result);
                    return result;
            }
            throw new Exception("Unknown node type");
        }
    }
}
