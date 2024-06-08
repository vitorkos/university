/*
id | var | valor?
1  | xis | 10   
2  | y   | null
*/

using System.Collections.Generic;

namespace SimpleCalculationInterpreter{
    public class SymbolTable{
        private Dictionary<string, int> _symbols = new Dictionary<string, int>();

        public void Set(string name, int value){
            _symbols[name] = value;
        }

        public int Get(string name){
            return _symbols.ContainsKey(name) ? _symbols[name] : 0;
        }
    }
}