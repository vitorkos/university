import json
import os
import csv

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


# Function to simulate the AFD using the delta transition function
def simulateAfd(automato, entrada):
    def delta(estado_atual, simbolo):
        for transicao in automato['transitions']:
            if int(transicao['from']) == estado_atual and transicao['read'] == simbolo:
                return int(transicao['to'])
        return None

    estado_atual = int(automato['initial'])

    for simbolo in entrada:
        estado_atual = delta(estado_atual, simbolo)
        if estado_atual is None:
            return False

    estados_finais = [int(estado) for estado in automato['final']]
    return estado_atual in estados_finais


# Main
json_file = "automato.aut"
automato_objeto = readJson(json_file)

input_file = "input.in"
input_csv = readInput(input_file)

for entrada, resultado_esperado in input_csv:
    resultado_obtido = simulateAfd(automato_objeto, entrada)
    print(f"Entrada: {entrada}, Resultado Esperado: {resultado_esperado}, Resultado Obtido: {resultado_obtido}")