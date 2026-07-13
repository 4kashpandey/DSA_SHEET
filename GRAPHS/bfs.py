from collections import deque


def bfs(graph, start_node):
    visited=set()

    queue=deque([start_node])
    visited.add(start_node)
    print("BFS Traversal Order:")
    while queue:
        current_node=queue.popleft()
        print(current_node, end=" -> ")
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

example_graph = {
    "A": ["B","C","J"],
    "B": ["D","E"],
    "C": ["F"],
    "D": ["G"],
    "E": ["H","I"],
    "F": ["A","B","C","D","E","G","H","I","J"],
    "G": ["H"],
    "H": ["G"],
    "I": ["H"],
    "J": ["A","B","C","D","E","G","H","I","J"]
}

bfs(example_graph, start_node="J")
