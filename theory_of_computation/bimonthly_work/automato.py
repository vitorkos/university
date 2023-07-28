import json
import os
import csv
import time

# Function to read the JSON file
def readJson(json_file):
    caminho_absoluto = os.path.abspath(os.path.join(os.path.dirname(__file__), json_file))
    with open(caminho_absoluto, 'r') as file:
        automato_json = json.load(file)
    return automato_json

# Function to read the input file
def readInput(input_file):
    caminho_absoluto = os.path.abspath(os.path.join(os.path.dirname(__file__), input_file))
    lista_dados = []
    with open(caminho_absoluto, newline='') as file:
        leitor_csv = csv.reader(file, delimiter=';')
        for linha in leitor_csv:
            entrada = linha[0].strip()
            resultado_esperado = linha[1].strip()
            lista_dados.append((entrada, resultado_esperado))
    return lista_dados


# Function to simulate the AFND with epsilon transitions using the delta transition function
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


# Main
json_file = "automato_afd.aut"
automato_objeto = readJson(json_file)

input_file = "input_afd.in"
input_csv = readInput(input_file)

for entrada, resultado_esperado in input_csv:
    start_time = time.time()
    resultado_obtido = simulateAfndEpsilon(automato_objeto, entrada)
    end_time = time.time()
    tempo_processamento = end_time - start_time
    print(f"Entrada: {entrada}, Resultado Esperado: {resultado_esperado}, Resultado Obtido: {resultado_obtido}, Tempo de Processamento: {tempo_processamento:.6f} segundos")
