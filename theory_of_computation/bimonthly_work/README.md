## Explicação do Código

Este código implementa um simulador para um Autômato Finito Não Determinístico (AFND) a partir de uma definição do autômato em formato JSON e de um conjunto de entradas em formato CSV. O resultado da simulação é escrito em um arquivo de saída, incluindo o resultado esperado e o tempo de processamento.

### Preparação Inicial

1. **Importações:** O código começa importando os módulos necessários:
   - `json`: para trabalhar com JSON
   - `os`: para lidar com caminhos de arquivo
   - `csv`: para ler arquivos CSV
   - `time`: para medir o tempo de processamento
   - `argparse`: para processar argumentos da linha de comando

2. **Função `readJson`:** Esta função lê um arquivo JSON e o converte em um objeto Python. Ela recebe o caminho para o arquivo JSON como entrada e retorna o objeto JSON.

3. **Função `readInput`:** Esta função lê um arquivo de entrada em formato CSV. Ela recebe o caminho para o arquivo de entrada como entrada e retorna uma lista de tuplas, onde cada tupla contém a entrada e o resultado esperado, ambos como strings.

### Simulação do AFND

4. **Função `simulateAfndEpsilon`:** Esta função realiza a simulação do AFND com transições epsilon. Ela recebe o objeto de definição do autômato (em formato JSON) e uma entrada (string) a ser verificada. A função implementa a função de transição delta e a função de transição delta-epsilon para simular as transições do autômato. O resultado é um booleano que indica se a entrada é aceita pelo autômato.

5. **Função `isAccepted`:** Esta função verifica se uma entrada é aceita pelo autômato. Ela recebe o objeto de definição do autômato (em formato JSON) e uma entrada (string) a ser verificada. A função percorre a entrada, verificando cada símbolo e seguindo as transições do autômato. O resultado é um booleano que indica se a entrada é aceita pelo autômato.

### Função Principal

6. **Função `main`:** Esta é a função principal do programa. Ela processa os argumentos da linha de comando, lê o arquivo de definição do autômato e o arquivo de entrada, executa a simulação para cada entrada do arquivo, escreve os resultados no arquivo de saída e mede o tempo de processamento.

7. **Processamento de Argumentos:** A função `main` utiliza o módulo `argparse` para processar os argumentos da linha de comando. São esperados três argumentos: o caminho para o arquivo de definição do autômato (formato .aut), o caminho para o arquivo de entrada (formato .in) e o caminho para o arquivo de saída (formato .out).

8. **Leitura do Arquivo JSON e do Arquivo de Entrada:** A função `main` lê o arquivo de definição do autômato (formato JSON) e o arquivo de entrada (formato CSV). O arquivo de entrada contém uma lista de entradas, cada uma associada a um resultado esperado.

9. **Simulação e Escrita dos Resultados:** A função `main` executa a simulação para cada entrada do arquivo de entrada utilizando a função `isAccepted`, comparando o resultado obtido com o resultado esperado e escrevendo essas informações no arquivo de saída, incluindo também o tempo de processamento para cada entrada.

10. **Execução da Função Principal:** O código verifica se está sendo executado como o programa principal (e não importado como módulo) e, se for o caso, chama a função `main`.