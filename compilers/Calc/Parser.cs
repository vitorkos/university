
using System.Linq.Expressions;
using System.Text.RegularExpressions;

namespace Calc {

    public class Parser {
        private Lexer _lexer;
        private SymbolTable _table;

        private Token _lookahead;

        public Parser(Lexer lexer){
            _lexer = lexer;            
            _lookahead = _lexer.NextToken();
        }

    public void Match(TokenType token){
        if (_lookahead.Type == token){
            _lookahead = _lexer.NextToken();
        } else {
            //emitir mensagem de erro
        }
    }

// cmd : PRINT expr | atrib 
    public String Cmd(){
        if (_lookahead.Type == TokenType.PRINT){
            Match(TokenType.PRINT);
            var value = Expr();
            return value.ToString();
        } else {
            Atrib();
            return String.Empty;
        }
    }
// atrib : VAR '=' expr
    public void Atrib(){
        Match(TokenType.VAR);
        Match(TokenType.EQ);
        Expr();
    }

// expr  : term rest
    public Double Expr(){
        Term();
        Rest();
    }

// rest  : '+' expr
//       | '-' expr
//       | __VAZIO__

    public void Rest(){
        if (_lookahead.Type == TokenType.SUM){
            Match(TokenType.SUM);
            Expr();
        } else if (_lookahead.Type == TokenType.SUB){
            Match(TokenType.SUB);
            Expr();
        } else {
            //testar se terminou a entrada (OK)
            // senão é erro
        }
    }
// term  : NUM 
//       | VAR 
//       | '('expr')' 

    public void Term(){
        if (_lookahead.Type == TokenType.NUM){
            Match(TokenType.NUM);
        } else if (_lookahead.Type == TokenType.VAR){
            Match(TokenType.VAR);
        } if (_lookahead.Type == TokenType.OPEN){
            Match(TokenType.OPEN);
            Expr();
            Match(TokenType.CLOSE);
        }
    }


    }

}