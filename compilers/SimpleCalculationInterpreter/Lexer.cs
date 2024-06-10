using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace SimpleCalculationInterpreter
{
    public enum TokenType
    {
        NUM, VAR, EQ, SUM, SUB, MUL, DIV, OPEN, CLOSE, PRINT, EOF, INVALID
    }

    public class Token
    {
        public TokenType Type { get; }
        public string Value { get; }

        public Token(TokenType type, string value)
        {
            Type = type;
            Value = value;
        }

        public override string ToString()
        {
            return $"{Type}({Value})";
        }
    }

    public class Lexer
    {
        private static readonly Regex TokenPattern = new Regex(@"\s*(?:(\d+)|([a-z]+)|(\=)|(\+)|(\-)|(\*)|(\/)|(\()|(\))|(PRINT)|(.))");

        private string _text;
        private int _position;

        public Lexer(string text)
        {
            _text = text;
            _position = 0;
        }

        public Token GetNextToken()
        {
            if (_position >= _text.Length)
            {
                return new Token(TokenType.EOF, string.Empty);
            }

            var match = TokenPattern.Match(_text, _position);

            if (!match.Success)
            {
                return new Token(TokenType.INVALID, _text[_position++].ToString());
            }

            _position = match.Index + match.Length;

            if (match.Groups[1].Success) return new Token(TokenType.NUM, match.Groups[1].Value);
            if (match.Groups[2].Success) return new Token(TokenType.VAR, match.Groups[2].Value);
            if (match.Groups[3].Success) return new Token(TokenType.EQ, match.Groups[3].Value);
            if (match.Groups[4].Success) return new Token(TokenType.SUM, match.Groups[4].Value);
            if (match.Groups[5].Success) return new Token(TokenType.SUB, match.Groups[5].Value);
            if (match.Groups[6].Success) return new Token(TokenType.MUL, match.Groups[6].Value);
            if (match.Groups[7].Success) return new Token(TokenType.DIV, match.Groups[7].Value);
            if (match.Groups[8].Success) return new Token(TokenType.OPEN, match.Groups[8].Value);
            if (match.Groups[9].Success) return new Token(TokenType.CLOSE, match.Groups[9].Value);
            if (match.Groups[10].Success) return new Token(TokenType.PRINT, match.Groups[10].Value);

            return new Token(TokenType.INVALID, match.Groups[11].Value);
        }
    }
}
