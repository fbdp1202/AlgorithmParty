#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 400;
const int MAX_V = (MAX_N+1)*2;
const int S = MAX_V-1;
const int E = MAX_V-2;
const int INF= 1e9;

int N, M;
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int d[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int main() {
	scanf("%d%d", &N, &M);
	// source to node
	for (int i=0; i<N; i++) {
		c[S][i] = 1;
		adj[i].push_back(S);
		adj[S].push_back(i);
	}

	for (int i=MAX_N; i<MAX_N+M; i++) {
		c[i][E] = 1;
		adj[i].push_back(E);
		adj[E].push_back(i);
	}

	for (int i=0; i<N; i++) {
		int num; scanf("%d", &num);
		while (num--) {
			int x, y;
			scanf("%d%d", &x, &y); x+=MAX_N-1;
			c[i][x] = 1;
			d[i][x] = y;
			d[x][i] = -y;
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
	}

	int result = 0;
	int cnt = 0;
	while (1) {
		int prev[MAX_V], dist[MAX_V];
		bool inQ[MAX_V] = {0};
		queue<int> Q;
		fill(prev, prev+MAX_V, -1);
		fill(dist, dist+MAX_V, INF);
		dist[S] = 0;
		inQ[S] = true;
		Q.push(S);

		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;
			for (int next: adj[curr]) {
				if (c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					if (!inQ[next]) {
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (prev[E] == -1) break;

		int flow = INF;
		for (int i=E; i!=S; i=prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		cnt += flow;
		for (int i=E; i!=S; i=prev[i]) {
			result += flow *d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
	}
	printf("%d\n%d\n", cnt, result);
	return 0;
}