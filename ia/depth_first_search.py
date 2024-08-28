class Graph:
    def __init__(self):
        self.graph = {}

    def adicionar_aresta(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
        self.graph[u].append(v)
        self.graph[v].append(u)  # Assuming it's an undirected graph

    def dfs(self, start, end):
        stack = [(start, [start])]
        visited = set()

        while stack:
            (vertex, path) = stack.pop()

            if vertex not in visited:
                if vertex == end:
                    return path  # Return the path if end is reached

                visited.add(vertex)

                for neighbor in self.graph[vertex]:
                    if neighbor not in visited:
                        stack.append((neighbor, path + [neighbor]))

        return None  # Return None if no path is found

# Create the graph
grafo = Graph()

# Add edges
grafo.adicionar_aresta('Neamt', 'Iasi')
grafo.adicionar_aresta('Iasi', 'Vaslui')
grafo.adicionar_aresta('Vaslui', 'Urziceni')
grafo.adicionar_aresta('Urziceni', 'Hirsova')
grafo.adicionar_aresta('Hirsova', 'Eforie')
grafo.adicionar_aresta('Urziceni', 'Bucharest')
grafo.adicionar_aresta('Bucharest', 'Giurgiu')
grafo.adicionar_aresta('Bucharest', 'Pitesti')
grafo.adicionar_aresta('Bucharest', 'Fagaras')
grafo.adicionar_aresta('Fagaras', 'Sibiu')
grafo.adicionar_aresta('Pitesti', 'Rimnicu Vilcea')
grafo.adicionar_aresta('Craiova', 'Rimnicu Vilcea')
grafo.adicionar_aresta('Pitesti', 'Craiova')
grafo.adicionar_aresta('Rimnicu Vilcea', 'Sibiu')
grafo.adicionar_aresta('Sibiu', 'Arad')
grafo.adicionar_aresta('Sibiu', 'Oradea')
grafo.adicionar_aresta('Oradea', 'Zerind')
grafo.adicionar_aresta('Arad', 'Zerind')
grafo.adicionar_aresta('Arad', 'Timisoara')
grafo.adicionar_aresta('Lugoj', 'Timisoara')
grafo.adicionar_aresta('Lugoj', 'Mehadia')
grafo.adicionar_aresta('Dobreta', 'Mehadia')
grafo.adicionar_aresta('Dobreta', 'Craiova')

# Example usage
start_node = 'Oradea'
end_node = 'Neamt'

path = grafo.dfs(start_node, end_node)
if path:
    print(f"Caminho de {start_node} até {end_node}: {path}")
else:
    print(f"Nenhum caminho entre {start_node} para {end_node}")
