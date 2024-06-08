using System;
using System.Collections.Generic;

namespace SimpleCalculationInterpreter{
    public class Parser{
        private List<Token> _tokens;
        private int _pos;
        private Token _currentToken;

        public Parser(List<Token> tokens){
            _tokens = tokens;
            _pos = 0;
            _currentToken = _tokens[_pos];
        }

        private void Eat(TokenType tokenType){
            if (_currentToken.Type == tokenType){
                _pos++;
                _currentToken = _pos < _tokens.Count ? _tokens[_pos] : new Token(TokenType.EOF, "");
            }
            else{
                throw new Exception($"Expected token {tokenType} but got {_currentToken.Type}");
            }
        }

        private dynamic Expr()
        {
            var result = Term();
            while (_currentToken.Type == TokenType.SUM || _currentToken.Type == TokenType.SUB){
                if (_currentToken.Type == TokenType.SUM){
                    Eat(TokenType.SUM);
                    result += Term();
                }
                else if (_currentToken.Type == TokenType.SUB){
                    Eat(TokenType.SUB);
                    result -= Term();
                }
            }
            return result;
        }

        private dynamic Term(){
            var token = _currentToken;
            if (token.Type == TokenType.NUM){
                Eat(TokenType.NUM);
                return int.Parse(token.Value);
            }
            else if (token.Type == TokenType.VAR){
                Eat(TokenType.VAR);
                return token.Value;
            }
            else if (token.Type == TokenType.OPEN){
                Eat(TokenType.OPEN);
                var result = Expr();
                Eat(TokenType.CLOSE);
                return result;
            }
            throw new Exception("Invalid term");
        }

        public dynamic Parse(){
            if (_currentToken.Type == TokenType.PRINT){
                Eat(TokenType.PRINT);
                var value = Expr();
                return new { Command = "PRINT", Value = value };
            }
            else if (_currentToken.Type == TokenType.VAR){
                var varName = _currentToken.Value;
                Eat(TokenType.VAR);
                Eat(TokenType.EQ);
                var value = Expr();
                return new { Command = "ASSIGN", Variable = varName, Value = value };
            }
            throw new Exception("Invalid command");
        }

    }
}