using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace SimpleCalculationInterpreter
{
    public enum TokenType
    {
        PRINT, VAR, NUM, EQ, SUM, SUB, OPEN, CLOSE, EOF
    }

    public class Token
    {
        public TokenType Type { get; set; }
        public string Value { get; set; }

        public Token(TokenType type, string value)
        {
            Type = type;
            Value = value;
        }
    }

    public class Lexer
    {
        private string _text;
        private int _pos;
        private char _currentChar;

        private static readonly Regex VarRegex = new Regex(@"^[a-z]+$");


        public Lexer(string text){
            _text = text;
            _pos = 0;
            _currentChar = _text[_pos];
        }

        private void Advance(){
            _pos++;
            _currentChar = _pos < _text.Length ? _text[_pos] : '\0';
        }

        private void SkipWhitespace(){
            while (_currentChar != '\0' && char.IsWhiteSpace(_currentChar)){
                Advance();
            }
        }

        private string Integer(){
            string result = "";
            while (_currentChar != '\0' && char.IsDigit(_currentChar)){
                result += _currentChar;
                Advance();
            }
            return result;
        }

        private string Var(){
            string result = "";
            while (_currentChar != '\0' && char.IsLetter(_currentChar)){
                result += _currentChar;
                Advance();
            }
            if (!VarRegex.IsMatch(result)){
                throw new Exception($"Invalid variable name: {result}");
            }
            return result;
        }

        public List<Token> GetTokens()
        {
            List<Token> tokens = new List<Token>();

            while (_currentChar != '\0')
            {
                if (char.IsWhiteSpace(_currentChar)){
                    SkipWhitespace();
                    continue;
                }

                if (_currentChar == '+'){
                    tokens.Add(new Token(TokenType.SUM, "+"));
                    Advance();
                    continue;
                }

                if (_currentChar == '-'){
                    tokens.Add(new Token(TokenType.SUB, "-"));
                    Advance();
                    continue;
                }

                if (_currentChar == '='){
                    tokens.Add(new Token(TokenType.EQ, "="));
                    Advance();
                    continue;
                }

                if (_currentChar == '('){
                    tokens.Add(new Token(TokenType.OPEN, "("));
                    Advance();
                    continue;
                }

                if (_currentChar == ')'){
                    tokens.Add(new Token(TokenType.CLOSE, ")"));
                    Advance();
                    continue;
                }

                if (char.IsDigit(_currentChar)){
                    tokens.Add(new Token(TokenType.NUM, Integer()));
                    continue;
                }

                if (char.IsLetter(_currentChar)){
                    string varName = Var();
                    if (varName == "PRINT"){
                        tokens.Add(new Token(TokenType.PRINT, "PRINT"));
                    }
                    else{
                        tokens.Add(new Token(TokenType.VAR, varName));
                    }
                    continue;
                }

                throw new Exception($"Invalid character: {_currentChar}");
            }

            tokens.Add(new Token(TokenType.EOF, ""));
            return tokens;
        }

    }
}
