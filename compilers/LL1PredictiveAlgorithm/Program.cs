using System;
using System.Collections.Generic;
using System.IO;

class LL1Parser
{
    private Dictionary<string, Dictionary<string, string>> parseTable;
    private Stack<string> stack;

    public LL1Parser(string parseTableFilePath)
    {
        parseTable = new Dictionary<string, Dictionary<string, string>>();
        stack = new Stack<string>();
        LoadParseTable(parseTableFilePath);
    }

    private void LoadParseTable(string filePath)
    {
        using (var reader = new StreamReader(filePath))
        {
            var header = reader.ReadLine().Split(',');
            while (!reader.EndOfStream)
            {
                var line = reader.ReadLine().Split(',');
                var rowNonTerminal = line[0].Trim();
                parseTable[rowNonTerminal] = new Dictionary<string, string>();
                for (int i = 1; i < line.Length; i++)
                {
                    parseTable[rowNonTerminal][header[i].Trim()] = line[i].Trim();
                }
            }
        }
    }

    public bool Parse(List<string> tokens)
    {
        tokens.Add("$");  // Adicionando o marcador de fim
        stack.Push("$");
        stack.Push("E");  // Símbolo inicial

        int index = 0;
        string token = tokens[index];

        while (stack.Count > 0)
        {
            string top = stack.Pop();
            Console.WriteLine($"Pilha: {string.Join(", ", stack)}"); // Para depuração
            Console.WriteLine($"Token atual: {token}"); // Para depuração

            if (IsTerminal(top))
            {
                if (top == token)
                {
                    index++;
                    if (index < tokens.Count)
                    {
                        token = tokens[index];
                    }
                }
                else
                {
                    Console.WriteLine($"Erro: Esperado '{top}', encontrado '{token}'.");
                    return false;
                }
            }
            else if (top == "ε")
            {
                continue;  // Produção vazia
            }
            else
            {
                if (parseTable.ContainsKey(top) && parseTable[top].ContainsKey(token))
                {
                    string production = parseTable[top][token];
                    if (!string.IsNullOrEmpty(production))
                    {
                        Console.WriteLine($"Produção: {top} -> {production}"); // Para depuração
                        var productionRightSide = production.Replace("->", "").Trim().Split(' ');

                        for (int i = productionRightSide.Length - 1; i >= 0; i--)
                        {
                            if (productionRightSide[i] != "ε") // Não empilhar epsilon
                            {
                                stack.Push(productionRightSide[i]);
                            }
                        }
                    }
                    else
                    {
                        Console.WriteLine($"Erro: Nenhuma regra para '{top}' com entrada '{token}'.");
                        return false;
                    }
                }
                else
                {
                    Console.WriteLine($"Erro: Não é possível derivar '{top}' a partir de '{token}'.");
                    return false;
                }
            }
        }

        return token == "$";
    }

    private bool IsTerminal(string symbol)
    {
        // Assume terminais como id, +, *, (, ) e $ 
        return !string.IsNullOrEmpty(symbol) && (symbol == "id" || symbol == "+" || symbol == "*" || symbol == "(" || symbol == ")" || symbol == "$");
    }

    public static void Main(string[] args)
    {
        var parser = new LL1Parser("parse_table.csv");

        var input = "id + id * id".Split(' ');  // Exemplo de entrada tokenizada
        if (parser.Parse(new List<string>(input)))
        {
            Console.WriteLine("Análise bem-sucedida!");
        }
        else
        {
            Console.WriteLine("Erro durante a análise.");
        }
    }
}
