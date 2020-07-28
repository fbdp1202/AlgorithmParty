#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_V = (MAX_N+1)*2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1e9;

int N, M;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int d[MAX_V][MAX_V];

vector<int> adj[MAX_V];

int main() {
	scanf("%d%d", &N, &M);

	// people to sink
	for (int i=MAX_N; i<MAX_N + N; i++) {
		scanf("%d", &c[i][E]);
		adj[i].push_back(E);
		adj[E].push_back(i);
	}

	// source to store
	for (int i=0; i<M; i++) {
		scanf("%d", &c[S][i]);
		adj[i].push_back(S);
		adj[S].push_back(i);
	}

	for (int i=0; i<M; i++) {
		for (int j=MAX_N; j<MAX_N+N; j++) {
			scanf("%d", &c[i][j]);
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	for (int i=0; i<M; i++) {
		for (int j=MAX_N; j<MAX_N+N; j++) {
			scanf("%d", &d[i][j]);
			d[j][i] = -d[i][j];
		}
	}

	int result = 0;
	int maxFlow = 0;

	while (1) {
		int prev[MAX_V], dist[MAX_V];
		fill(prev, prev+MAX_V, -1);
		fill(dist, dist+MAX_V, INF);
		bool inQ[MAX_V] = {0};

		queue<int> Q;
		Q.push(S);
		inQ[S] = true;
		dist[S] = 0;

		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;
			for (int next: adj[curr]) {
				if (c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					if (!inQ[next]) {
						inQ[next] = true;
						Q.push(next);
					}
				}
			}

		}
		if (prev[E] == -1) break;

		int flow = INF;

		for (int i=E; i!=S; i=prev[i])
			flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);

		for (int i=E; i!=S; i=prev[i]) {
			result += flow *d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		maxFlow += flow;
	}
	printf("%d\n%d\n", maxFlow, result);

	return 0;
}