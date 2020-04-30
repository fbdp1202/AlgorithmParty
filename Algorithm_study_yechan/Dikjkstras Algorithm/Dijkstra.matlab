function Dijkstra(Graph, source):
	dist[soruce] <- 0

	crete vertex set Q

	for each vertex v in Graph:
		if (v != soruce)
			dist[v] <- INFINITY
		prev[v] <- UNDEFINED

		Q.add_with_priority(v, dist[v])

	while Q is not empty:
		u <- Q.extract_min()
		for each neighbor v of u:
			alt <- dist[u] + length(u, v)
			if alt < dist[v]
				dist[v] <- alt
				prev[v] <- u
				Q.decrease_priority(v, alt)
				
	return dist, prev