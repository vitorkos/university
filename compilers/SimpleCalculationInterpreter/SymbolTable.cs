using System.Collections.Generic;

namespace SimpleCalculationInterpreter
{
    public class SymbolTable
    {
        private Dictionary<string, int> _symbols = new Dictionary<string, int>();

        public int Get(string name)
        {
            if (_symbols.TryGetValue(name, out var value))
            {
                return value;
            }
            throw new Exception($"Variable '{name}' not defined");
        }

        public void Set(string name, int value)
        {
            _symbols[name] = value;
        }
    }
}
