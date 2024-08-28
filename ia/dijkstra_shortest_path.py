import heapq

class Grafo:
    def __init__(self):
        self.vertices = {}

    def adicionar_vertice(self, vertice):
        self.vertices[vertice] = {}

    def adicionar_aresta(self, origem, destino, peso):
        if origem not in self.vertices:
            self.adicionar_vertice(origem)
        if destino not in self.vertices:
            self.adicionar_vertice(destino)
        self.vertices[origem][destino] = peso
        self.vertices[destino][origem] = peso  # Se for um grafo direcionado, remova esta linha.

    def dijkstra(self, origem, destino):
        fila_prioridade = []
        heapq.heappush(fila_prioridade, (0, origem))
        distancia = {vertice: float('infinity') for vertice in self.vertices}
        distancia[origem] = 0
        caminho_anterior = {}

        while fila_prioridade:
            distancia_atual, vertice_atual = heapq.heappop(fila_prioridade)
            if distancia_atual > distancia[vertice_atual]:
                continue

            if vertice_atual == destino:
                break

            for vizinho, peso in self.vertices[vertice_atual].items():
                nova_distancia = distancia_atual + peso
                if nova_distancia < distancia[vizinho]:
                    distancia[vizinho] = nova_distancia
                    caminho_anterior[vizinho] = vertice_atual
                    heapq.heappush(fila_prioridade, (nova_distancia, vizinho))

        caminho = [destino]
        vertice_atual = destino
        while vertice_atual != origem:
            vertice_atual = caminho_anterior[vertice_atual]
            caminho.append(vertice_atual)
        caminho.reverse()

        return distancia[destino], caminho

grafo = Grafo()
grafo.adicionar_aresta('Neamnt', 'Iasi', 87)
grafo.adicionar_aresta('Iasi', 'Vaslui', 92)
grafo.adicionar_aresta('Vaslui', 'Urziceni', 142)
grafo.adicionar_aresta('Urziceni', 'Hirsova', 98)
grafo.adicionar_aresta('Hirsova', 'Eforie', 86)
grafo.adicionar_aresta('Urziceni', 'Bucharest', 85)
grafo.adicionar_aresta('Bucharest', 'Giurgiu', 90)
grafo.adicionar_aresta('Bucharest', 'Pitest', 101)
grafo.adicionar_aresta('Bucharest', 'Fegaras', 211)
grafo.adicionar_aresta('Fegaras', 'Sibiu', 99)
grafo.adicionar_aresta('Pitest', 'Rimnicu Vilcea', 97)
grafo.adicionar_aresta('Craivoa', 'Rimnicu Vilcea', 146)
grafo.adicionar_aresta('Pitest', 'Craivoa', 138)
grafo.adicionar_aresta('Rimnicu Vilcea', 'Sibiu', 80)
grafo.adicionar_aresta('Sibiu', 'Arad', 140)
grafo.adicionar_aresta('Sibiu', 'Oradea', 151)
grafo.adicionar_aresta('Oradea', 'Zerind', 71)
grafo.adicionar_aresta('Arad', 'Zerind', 75)
grafo.adicionar_aresta('Arad', 'Timisoara', 118)
grafo.adicionar_aresta('Lugoj', 'Timisoara', 111)
grafo.adicionar_aresta('Lugoj', 'Mehadia', 70)
grafo.adicionar_aresta('Dobreta', 'Mehadia', 75)
grafo.adicionar_aresta('Dobreta', 'Craivoa', 120)

menor_caminho, caminho = grafo.dijkstra('Neamnt', 'Hirsova')
print(f"Menor caminho: {caminho} com custo {menor_caminho}")