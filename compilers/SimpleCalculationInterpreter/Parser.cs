using System;

namespace SimpleCalculationInterpreter
{
    public class Parser
    {
        private Lexer _lexer;
        private Token _currentToken;

        public Parser(Lexer lexer)
        {
            _lexer = lexer;
            _currentToken = _lexer.GetNextToken();
        }

        private void Eat(TokenType tokenType)
        {
            if (_currentToken.Type == tokenType)
            {
                _currentToken = _lexer.GetNextToken();
            }
            else
            {
                throw new Exception($"Syntax error: expected {tokenType}, got {_currentToken.Type}");
            }
        }

        public Node Parse()
        {
            return Cmd();
        }

        private Node Cmd()
        {
            if (_currentToken.Type == TokenType.VAR)
            {
                return Atrib();
            }
            else if (_currentToken.Type == TokenType.PRINT)
            {
                Eat(TokenType.PRINT);
                return new PrintNode(Expr());
            }
            else
            {
                throw new Exception("Syntax error in command");
            }
        }

        private Node Atrib()
        {
            var varNode = new VarNode(_currentToken.Value);
            Eat(TokenType.VAR);
            Eat(TokenType.EQ);
            var exprNode = Expr();
            return new AssignNode(varNode, exprNode);
        }

        private Node Expr()
        {
            var node = Term();
            while (_currentToken.Type == TokenType.SUM || _currentToken.Type == TokenType.SUB)
            {
                var token = _currentToken;
                if (token.Type == TokenType.SUM)
                {
                    Eat(TokenType.SUM);
                }
                else if (token.Type == TokenType.SUB)
                {
                    Eat(TokenType.SUB);
                }
                node = new BinOpNode(node, token, Term());
            }
            return node;
        }

        private Node Term()
        {
            var node = Factor();
            while (_currentToken.Type == TokenType.MUL || _currentToken.Type == TokenType.DIV)
            {
                var token = _currentToken;
                if (token.Type == TokenType.MUL)
                {
                    Eat(TokenType.MUL);
                }
                else if (token.Type == TokenType.DIV)
                {
                    Eat(TokenType.DIV);
                }
                node = new BinOpNode(node, token, Factor());
            }
            return node;
        }

        private Node Factor()
        {
            var token = _currentToken;
            if (token.Type == TokenType.NUM)
            {
                Eat(TokenType.NUM);
                return new NumNode(int.Parse(token.Value));
            }
            else if (token.Type == TokenType.VAR)
            {
                Eat(TokenType.VAR);
                return new VarNode(token.Value);
            }
            else if (token.Type == TokenType.OPEN)
            {
                Eat(TokenType.OPEN);
                var node = Expr();
                Eat(TokenType.CLOSE);
                return node;
            }
            else
            {
                throw new Exception("Syntax error in factor");
            }
        }
    }

    public abstract class Node { }

    public class NumNode : Node
    {
        public int Value { get; }

        public NumNode(int value)
        {
            Value = value;
        }
    }

    public class VarNode : Node
    {
        public string Name { get; }

        public VarNode(string name)
        {
            Name = name;
        }
    }

    public class AssignNode : Node
    {
        public VarNode Variable { get; }
        public Node Value { get; }

        public AssignNode(VarNode variable, Node value)
        {
            Variable = variable;
            Value = value;
        }
    }

    public class BinOpNode : Node
    {
        public Node Left { get; }
        public Token Op { get; }
        public Node Right { get; }

        public BinOpNode(Node left, Token op, Node right)
        {
            Left = left;
            Op = op;
            Right = right;
        }
    }

    public class PrintNode : Node
    {
        public Node Expression { get; }

        public PrintNode(Node expression)
        {
            Expression = expression;
        }
    }
}
