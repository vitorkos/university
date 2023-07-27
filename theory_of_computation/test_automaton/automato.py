import json
import os
import csv

# Function to read the JSON file
def readJson(json_file):
    caminho_absoluto = os.path.abspath(os.path.join(os.path.dirname(__file__), json_file))
    with open(caminho_absoluto, 'r') as file:
        automato_json = json.load(file)

    # Convertendo o campo "from" para inteiros
    for transicao in automato_json["transitions"]:
        transicao["from"] = int(transicao["from"])

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

# Function to simulate the AFND using the delta transition function
def simulateAfnd(automato, entrada):
    # Delta function for state transitions
    def delta(estado_atual, simbolo):
        transicoes = [transicao for transicao in automato['transitions'] if transicao['from'] == estado_atual and transicao['read'] == simbolo]
        estados_destino = [transicao['to'] for transicao in transicoes]
        return estados_destino

    estados_atuais = [automato['initial']]

    for simbolo in entrada:
        novos_estados_atuais = []
        for estado_atual in estados_atuais:
            estados_destino = delta(estado_atual, simbolo)
            novos_estados_atuais.extend(estados_destino)
        
        # Verifica se há transições vazias
        estados_destino_vazio = delta(estado_atual, '')
        novos_estados_atuais.extend(estados_destino_vazio)

        # Atualiza os estados atuais com os novos estados
        estados_atuais = list(set(novos_estados_atuais))

    estados_finais = automato['final']

    if any(estado in estados_finais for estado in estados_atuais):
        return True
    else:
        return False



json_file = "automato.aut"
automato_objeto = readJson(json_file)

input_file = "input.in"
input_csv = readInput(input_file)

for entrada, resultado_esperado in input_csv:
    resultado_simulacao = simulateAfnd(automato_objeto, entrada)
    print(f"Entrada: {entrada}, Resultado Esperado: {resultado_esperado}, Resultado Simulação: {resultado_simulacao}")
