import heapq

def dijkstra(graph, start):
	distances = {vertex: flaot('inf') for vertex in graph}
	distances[start] = 0

	queue = []
	for vertex, distance in distances.items():
		heapq.heappush(queue, [vertex, distance])

	while queue:

		current_vertex, current_distance = heapq.heappop(queue)
		for adjacent, weight in graph[currenct_vertex].items():
			distance = distances[current_vertex] + weight
			if distance < distances[adjacent]:
				distances[adjacent] = distance

	return distances


mygraph = {
	'A': {'B': 8, 'C': 1, 'D': 2},
	'B': {},
	'C': {'B': 5, 'D': 2},
	'D': {'E': 3, 'F': 5},
	'E': {'F': 1},
	'F': {'A': 5}
}

print(dijkstra(mygraph, 'A'))