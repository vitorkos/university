import json
import os
import csv
import time
import argparse

# Função para ler o arquivo JSON
def readJson(json_file):
    caminho_absoluto = os.path.abspath(json_file)
    with open(caminho_absoluto, 'r') as file:
        automato_json = json.load(file)
    return automato_json

# Função para ler o arquivo de entrada
def readInput(input_file):
    caminho_absoluto = os.path.abspath(input_file)
    lista_dados = []
    with open(caminho_absoluto, newline='') as file:
        leitor_csv = csv.reader(file, delimiter=';')
        for linha in leitor_csv:
            entrada = linha[0].strip()
            resultado_esperado = linha[1].strip()
            lista_dados.append((entrada, resultado_esperado))
    return lista_dados


# Função para simular o AFND com transições epsilon usando a função de transição delta
def simulateAfndEpsilon(automato, entrada):
    def delta(estado_atual, simbolo):
        estados_destino = set()
        for transicao in automato['transitions']:
            if int(transicao['from']) == estado_atual and transicao['read'] == simbolo:
                estados_destino.add(int(transicao['to']))
        return estados_destino

    def delta_epsilon(estados_atuais):
        novos_estados_atuais = set(estados_atuais)
        for estado_atual in estados_atuais:
            for transicao in automato['transitions']:
                if int(transicao['from']) == estado_atual and transicao['read'] == '':
                    novos_estados_atuais.add(int(transicao['to']))
        return novos_estados_atuais

    estados_atuais = {int(automato['initial'])}

    for simbolo in entrada:
        novos_estados_atuais = set()
        for estado_atual in estados_atuais:
            estados_destino = delta(estado_atual, simbolo)
            novos_estados_atuais.update(estados_destino)
        estados_atuais = novos_estados_atuais.union(delta_epsilon(estados_atuais))

    estados_finais = {int(estado) for estado in automato['final']}
    return any(estado in estados_finais for estado in estados_atuais)


# Função principal
def main():
    parser = argparse.ArgumentParser(description="Simula um AFND com transições epsilon a partir de um arquivo JSON e um arquivo de entrada CSV.")
    parser.add_argument("automato", type=str, help="Caminho para o arquivo de definição do autômato (formato .aut)")
    parser.add_argument("input", type=str, help="Caminho para o arquivo de entrada (formato .in)")
    parser.add_argument("output", type=str, help="Caminho para o arquivo de saída (formato .out)")
    args = parser.parse_args()

    automato_file = args.automato
    automato_objeto = readJson(automato_file)

    input_file = args.input
    input_csv = readInput(input_file)

    output_file = args.output

    with open(output_file, 'w') as outfile:
        for entrada, resultado_esperado in input_csv:
            start_time = time.time()
            resultado_obtido = simulateAfndEpsilon(automato_objeto, entrada)
            end_time = time.time()
            tempo_processamento = end_time - start_time
            outfile.write(f"Entrada: {entrada}, Resultado Esperado: {resultado_esperado}, Resultado Obtido: {resultado_obtido}, Tempo de Processamento: {tempo_processamento:.6f} segundos\n")

if __name__ == "__main__":
    main()