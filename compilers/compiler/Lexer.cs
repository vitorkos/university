// NUM = número natural(0...999)
// VAR, 1 = variável (uma letra)
// 
// EQ '='
// SUM '+'
// SUB '-'
// OPEN '('
// CLOSE ')'
// PRINT 'PRINT'
// UNK

namespace Calc{
    public class Lexer{
        public String Input{get; set;}
        private int _ptr;
        public Lexer(String input){
            Input = input;
            _ptr = 0;
        }
        private char Scan(){
            if(_ptr >= Input.Length)
                return EOF;
            return Input(_ptr++);
        }
        public struct Token{
            TokenType Type;
            int Value;
        }
        public Token NextToken(){
            char c = Scan();
            while(c == '' || c == '\t'){
                c = Scan();
            }
            switch(c){
                case '+' : return new Token(Type = TokenType.SUM);
                case '-' : return new Token(Type = TokenType.SUB);
                case '(' : return new Token(Type = TokenType.OPEN);
                case ')' : return new Token(Type = TokenType.CLOSE);
                case '=' : return new Token(Type = TokenType.EQ);
            }
            if(char.IsDigit(c)){ // encontrei um NUM

            }
            if(char.IsUpper(c)){ // se pa PRINT

            }
            if(char.IsLower(c)){//variavel
            
            }
            return new Token(Type = TokenType.UNK);
        }
        public enum TokenType{
            VAR, SUM, SUB, OPEN, CLOSE, PRINT, EQ, UNK
        }
    }
}