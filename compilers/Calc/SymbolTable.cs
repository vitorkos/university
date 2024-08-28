2/*
id | var | valor?
1  | xis | 10   
2  | y   | null
*/

namespace Calc{
    public class SymbolTable{

        private List<Entry> _symbols;

        public SymbolTable(){
            _symbols = new List<Entry>();
        }

        public int AddSymbol(String varName){
            return -1;
        }

        public Entry GetSymbol(int index){
            
        }

    }

    public struct Entry {
        public String VarName;
        public Double? Value;
    }
}