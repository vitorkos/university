// VAR,1 = variável (uma sequencia de letras minúsculas), atributo -> tabela de símbolos
// NUM,99 = número natural (0 ... 999999) , Atributo: valor
// EQ '='
// SUM '+'
// SUB '-'
// OPEN '('
// CLOSE ')'
// PRINT 'PRINT'

namespace Calc {
   public class Lexer {
        public static char EOF = '\0';

        public string Input {get;set;}
        private int _ptr;
        public SymbolTable Table{get; private set;}

        public Lexer(String input, SymbolTable table){
            Input = input;
            _ptr = 0;
            Table = table;
        }

        private char Scan(){
            if (_ptr == Input.Length)
                return EOF;            
            return Input[_ptr++];
        }

        private int ParseInt(char c){
            return c switch
            {
                '0' => 0,
                '1' => 1,
                '2' => 2,
                '3' => 3,
                '4' => 4,
                '5' => 5,
                '6' => 6,
                '7' => 7,
                '8' => 8,
                '9' => 9,
                _ => -1,
            };
        }

        public Token NextToken(){  //x =  2 + 2
            char? c = Scan();
            if (c == null)
               return new Token{Type = TokenType.EOF};
            //remover espaços em branco
            while (c == ' ' || c == '\t'){
                c = Scan();
            }
            switch (c){  //casar todos os tokens com 1 caractere
                case '+' : return new Token{Type = TokenType.SUM};
                case '-' : return new Token{Type = TokenType.SUB};
                case '(' : return new Token{Type = TokenType.OPEN};
                case ')' : return new Token{Type = TokenType.CLOSE};
                case '=' : return new Token{Type = TokenType.EQ};
            }

            if (Char.IsDigit(c.Value)){
                var x = ParseInt(c.Value);
                c = Scan();
                while (Char.IsDigit(c.Value)){
                    x = x*10+ParseInt(c.Value);
                    c = Scan();
                }
                _ptr--;
                return new Token{Type = TokenType.NUM, Value = x};
            }
            if (Char.IsUpper(c.Value)){ //sinto cheiro de PRINT
                if (c == 'P'){

                }
                return new Token{Type = TokenType.UNK};
            }
            if (Char.IsLower(c.Value)){ //parece uma variavel
                var v = c.ToString();
                c = Scan();
                while (Char.IsLower(c.Value)){
                    v = v + c.ToString();
                    c = Scan();
                }
                _ptr--;
                return new Token{Type = TokenType.VAR, Value = _table.AddSymbol(v)};//implementar tabela de símbolos
            }
            return new Token{Type = TokenType.UNK};
        }
   }

   public struct Token{
        public TokenType Type;
        public int Value;
   }

   public enum TokenType{
        VAR, NUM, EQ, SUB, SUM, OPEN, CLOSE, PRINT, EOF, UNK
   }
}