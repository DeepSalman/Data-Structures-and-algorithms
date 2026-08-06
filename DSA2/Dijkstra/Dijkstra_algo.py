import heapq
def dijkstra(graph,start):
    distance = {node: float('inf') for node in graph}
    distance[start]=0
    pq =[(0,start)]

    while pq:
        current_dist,node = heapq.heappop(pq)
        if current_dist>distance[node]:
            continue
        for neighbor,weight in graph[node].items():
            new_dist = current_dist+weight
            if new_dist<distance[neighbor]:
                distance[neighbor]=new_dist
                heapq.heappush(pq,(new_dist,neighbor))
    return distance


