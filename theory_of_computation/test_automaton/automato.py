#importing libs
import json
import os
import csv


#function to read the json file
def readJson(json_file):
    caminho_absoluto = os.path.abspath(os.path.join(os.path.dirname(__file__), json_file))
    with open(caminho_absoluto, 'r') as file:
        automato_json = json.load(file)
    return automato_json

#function to read the input file
def readInput(input_cvs):
    caminho_absoluto = os.path.abspath(os.path.join(os.path.dirname(__file__), input_file))
    lista_dados = []
    with open(caminho_absoluto, newline='') as file:
        leitor_csv = csv.reader(file, delimiter=';')
        for linha in leitor_csv:
            input = linha[0].strip()
            saida_esperada = linha[1].strip()
            lista_dados.append((input, saida_esperada))
    return lista_dados


json_file = "automato.aut"
automato_objeto = readJson(json_file)

input_file = "input.in"
input_csv = readInput(input_file)


print("estado inicial: ", automato_objeto['initial'])
print("in1 : ", input_csv[0][0])