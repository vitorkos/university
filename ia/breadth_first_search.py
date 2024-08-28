
from collections import deque

def bfs(graph, start, final):
    visited = set()
    queue = deque([start])
    print("Grafo percorrendo:\n")
    count = 0
    notFound = True
    while queue and notFound:
        vertex = queue.popleft()
        if vertex not in visited:
            visited.add(vertex)
            print(count, ": ", vertex)
            queue.extend(graph[vertex] - visited)
            count = count + 1
            if (final == vertex):
              print("\nEncontrado\n")
              notFound = False
    if (notFound):
      print("\nNão encontrado\n")

# Example usage
graph = {
    'Neamnt': set(['Iasi']),
    'Iasi': set(['Vaslui']),
    'Vaslui': set(['Urziceni']),
    'Urziceni': set(['Hirsoa', 'Buchareast']),
    'Hirsoa': set(['Eforie']),
    'Eforie': set([]),
    'Buchareast': set(['Giurgiu', 'Fagaras', 'Pitest']),
    'Giurgiu': set([]),
    'Fagaras': set(['Sibiu']),
    'Pitest': set(['Rimnicu Vilcea', 'Craiova']),
    'Sibiu': set(['Oradea', 'Arad']),
    'Rimnicu Vilcea': set(['Sibiu', 'Craiova']),
    'Craiova': set(['Dobreta']),
    'Oradea': set(['Zerind']),
    'Arad': set(['Zerind', 'Timisoara']),
    'Dobreta': set(['Mehadia']),
    'Mehadia': set(['Lugoj']),
    'Lugoj': set(['Timisoara']),
    'Timisoara': set([]),
    'Zerind': set([]),
}

bfs(graph, 'Neamnt', 'Hirsoa')

bfs(graph, 'Arad', 'Timisora-Falso')