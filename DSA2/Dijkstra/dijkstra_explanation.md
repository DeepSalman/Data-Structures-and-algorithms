# Dijkstra Algorithm Explanation (for your code)

```python
import heapq


def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    pq = [(0, start)]  # (distance, node)

    while pq:
        current_dist, node = heapq.heappop(pq)

        if current_dist > distances[node]:
            continue

        for neighbor, weight in graph[node].items():
            new_dist = current_dist + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))

    return distances


# Example usage
graph = {
    'A': {'B': 4, 'C': 2},
    'B': {'D': 5},
    'C': {'B': 1, 'D': 8},
    'D': {}
}

print(dijkstra(graph, 'A'))
```

## Line-by-line explanation

### 1) `import heapq`
- Imports Python’s **min-heap** utility.
- We use it to always pick the node with the **smallest known distance**.

### 2) `def dijkstra(graph, start):`
- Defines a function to compute shortest distances from `start` to all nodes.

### 3) `distances = {node: float('inf') for node in graph}`
- Creates a dictionary where each node starts at distance **infinity**.
- This means “we do not know a path yet.”

### 4) `distances[start] = 0`
- Distance from start node to itself is `0`.

### 5) `pq = [(0, start)]`
- Initializes a priority queue with one element: `(distance, node)`.
- Starts with `(0, start)`.

### 6) `while pq:`
- Continue until there are no more nodes to process.

### 7) `current_dist, node = heapq.heappop(pq)`
- Removes the element with the smallest distance from the heap.

### 8) `if current_dist > distances[node]: continue`
- Skips outdated entries.
- Sometimes an older, worse distance remains in the heap after a better one was found.

### 9) `for neighbor, weight in graph[node].items():`
- Iterates over all neighbors of `node`.
- `weight` is the edge cost from `node` to `neighbor`.

### 10) `new_dist = current_dist + weight`
- Computes the candidate distance to the neighbor through the current node.

### 11) `if new_dist < distances[neighbor]:`
- If this new path is better than the previously known one, update it.

### 12) `distances[neighbor] = new_dist`
- Stores the improved shortest distance.

### 13) `heapq.heappush(pq, (new_dist, neighbor))`
- Pushes updated neighbor into heap for further exploration.

### 14) `return distances`
- Returns shortest distances from `start` to every node.

## Your graph meaning

```python
graph = {
    'A': {'B': 4, 'C': 2},
    'B': {'D': 5},
    'C': {'B': 1, 'D': 8},
    'D': {}
}
```

- `A -> B (4)`, `A -> C (2)`
- `B -> D (5)`
- `C -> B (1)`, `C -> D (8)`
- `D` has no outgoing edges

## Output for `dijkstra(graph, 'A')`

```python
{'A': 0, 'B': 3, 'C': 2, 'D': 8}
```

Why:
- `A -> C = 2`
- `A -> C -> B = 2 + 1 = 3` (better than `A -> B = 4`)
- `A -> C -> B -> D = 2 + 1 + 5 = 8` (better than `A -> C -> D = 10`)
