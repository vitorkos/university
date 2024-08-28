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

graph = {
    'value-1a': set(['value-2a', 'value-1b']),
    'value-1b': set(['value-1a', 'value-1c']),
    'value-1c': set(['value-1b', 'value-1d']),
    'value-1d': set(['value-1c', 'value-1e']),
    'value-1e': set(['value-1d', 'value-1f', 'value-2e']),
    'value-1f': set(['value-1e', 'value-1g']),
    'value-1g': set(['value-1f', 'value-1h']),
    'value-1h': set(['value-1g', 'value-1i']),
    'value-1i': set(['value-1h', 'value-2i']),

    'value-2a': set(['value-1a', 'value-3a']),
    'value-2e': set(['value-1e', 'value-3e']),
    'value-2i': set(['value-1i', 'value-3i']),

    'value-3a': set(['value-2a', 'value-4a']),
    'value-3c': set(['value-3d', 'value-4c']),
    'value-3d': set(['value-3c', 'value-3e']),
    'value-3e': set(['value-3d', 'value-3f', 'value-2e', 'value-4e']),
    'value-3f': set(['value-3e', 'value-3g']),
    'value-3g': set(['value-3f', 'value-4g']),
    'value-3i': set(['value-2i', 'value-4i']),

    'value-4a': set(['value-3a', 'value-4b']),
    'value-4b': set(['value-4a', 'value-4c']),
    'value-4c': set(['value-4b', 'value-3c', 'value-5c']),
    'value-4e': set(['value-3e', 'value-5e']),
    'value-4g': set(['value-3g', 'value-5g', 'value-4h']),
    'value-4h': set(['value-4g', 'value-4i']),
    'value-4i': set(['value-4h', 'value-3i']),

    'value-5c': set(['value-4c', 'value-6c']),
    'value-5e': set(['value-4e', 'value-6e']),
    'value-5g': set(['value-4g', 'value-6g']),

    'value-6a': set(['value-7a', 'value-6b']),
    'value-6b': set(['value-6a', 'value-6c']),
    'value-6c': set(['value-6b', 'value-6d', 'value-5c', 'value-7c']),
    'value-6d': set(['value-6c', 'value-6e']),
    'value-6e': set(['value-6d', 'value-6f', 'value-5e']),
    'value-6f': set(['value-6e', 'value-6g']),
    'value-6g': set(['value-6f', 'value-6h', 'value-5g', 'value-7g']),
    'value-6h': set(['value-6g', 'value-6i']),
    'value-6i': set(['value-6h', 'value-7i']),

    'value-7a': set(['value-6a', 'value-8a']),
    'value-7c': set(['value-6c', 'value-8c']),
    'value-7g': set(['value-6g', 'value-8g']),
    'value-7i': set(['value-6i', 'value-8i']),

    'value-8a': set(['value-7a', 'value-9a']),
    'value-8c': set(['value-7c', 'value-9c']),
    'value-8e': set(['value-9e']),
    'value-8g': set(['value-7g', 'value-9g']),
    'value-8i': set(['value-7i', 'value-9i']),

    'value-9a': set(['value-8a', 'value-10a']),
    'value-9c': set(['value-8c', 'value-10c']),
    'value-9d': set(['value-10d', 'value-9e']),
    'value-9e': set(['value-9d', 'value-10e', 'value-8e']),
    'value-9g': set(['value-8g', 'value-10g']),
    'value-9i': set(['value-8i', 'value-10i']),

    'value-10a': set(['value-9a', 'value-1value-1a']),
    'value-10c': set(['value-9c', 'value-1value-1c']),
    'value-10d': set(['value-9d', 'value-10e']),
    'value-10e': set(['value-10d', 'value-1value-1e', 'value-9e']),
    'value-10g': set(['value-9g', 'value-1value-1g']),
    'value-10i': set(['value-9i', 'value-1value-1i']),

    'value-1value-1a': set(['value-10a', 'value-1value-2a']),
    'value-1value-1c': set(['value-10c', 'value-1value-2c']),
    'value-1value-1e': set(['value-10e']),
    'value-1value-1g': set(['value-10g', 'value-1value-2g']),
    'value-1value-1i': set(['value-10i', 'value-1value-2i']),

    'value-1value-2a': set(['value-1value-1a', 'value-1value-3a']),
    'value-1value-2c': set(['value-1value-1c', 'value-1value-3c']),
    'value-1value-2g': set(['value-1value-1g', 'value-1value-3g']),
    'value-1value-2i': set(['value-1value-1i', 'value-1value-3i']),

    'value-1value-3a': set(['value-1value-2a', 'value-1value-3b']),
    'value-1value-3b': set(['value-1value-3a', 'value-1value-3c']),
    'value-1value-3c': set(['value-1value-3b', 'value-1value-3d', 'value-1value-2c', 'value-1value-4c']),
    'value-1value-3d': set(['value-1value-3c', 'value-1value-3e']),
    'value-1value-3e': set(['value-1value-3d', 'value-1value-3f', 'value-1value-4e']),
    'value-1value-3f': set(['value-1value-3e', 'value-1value-3g']),
    'value-1value-3g': set(['value-1value-3f', 'value-1value-3h', 'value-1value-2g', 'value-1value-4g']),
    'value-1value-3h': set(['value-1value-3g', 'value-1value-3i']),
    'value-1value-3i': set(['value-1value-2i', 'value-1value-3h']),

    'value-1value-4c': set(['value-1value-3c', 'value-1value-5c']),
    'value-1value-4e': set(['value-1value-3e', 'value-1value-5e']),
    'value-1value-4g': set(['value-1value-3g', 'value-1value-5g']),

    'value-1value-5a': set(['value-1value-6a', 'value-1value-5b']),
    'value-1value-5b': set(['value-1value-5a', 'value-1value-5c']),
    'value-1value-5c': set(['value-1value-5b', 'value-1value-4c', 'value-1value-6c']),
    'value-1value-5e': set(['value-1value-4e', 'value-1value-6e']),
    'value-1value-5g': set(['value-1value-4g', 'value-1value-6g', 'value-1value-5h']),
    'value-1value-5h': set(['value-1value-5g', 'value-1value-5i']),
    'value-1value-5i': set(['value-1value-5h', 'value-1value-6i']),

    'value-1value-6a': set(['value-1value-5a', 'value-1value-7a']),
    'value-1value-6c': set(['value-1value-5c', 'value-1value-6d']),
    'value-1value-6d': set(['value-1value-6c', 'value-1value-6e']),
    'value-1value-6e': set(['value-1value-6d', 'value-1value-6f', 'value-1value-5e', 'value-1value-7e']),
    'value-1value-6f': set(['value-1value-6e', 'value-1value-6g']),
    'value-1value-6g': set(['value-1value-6f', 'value-1value-5g']),
    'value-1value-6i': set(['value-1value-5i', 'value-1value-7i']),

    'value-1value-7a': set(['value-1value-6a', 'value-1value-8a']),
    'value-1value-7e': set(['value-1value-6e', 'value-1value-8e']),
    'value-1value-7i': set(['value-1value-6i', 'value-1value-8i']),

    'value-1value-8a': set(['value-1value-7a', 'value-1value-8b']),
    'value-1value-8b': set(['value-1value-8a', 'value-1value-8c']),
    'value-1value-8c': set(['value-1value-8b', 'value-1value-8d']),
    'value-1value-8d': set(['value-1value-8c', 'value-1value-8e']),
    'value-1value-8e': set(['value-1value-8d', 'value-1value-7e', 'value-1value-8f']),
    'value-1value-8f': set(['value-1value-8e', 'value-1value-8g']),
    'value-1value-8g': set(['value-1value-8h', 'value-1value-8f']),
    'value-1value-8h': set(['value-1value-8g', 'value-1value-8i']),
    'value-1value-8i': set(['value-1value-8h', 'value-1value-7i']),
}

initial_position = 'value-1value-1g'
first_ball = 'value-1value-8i'
second_ball = 'value-1a'

bfs(graph, initial_position, first_ball)