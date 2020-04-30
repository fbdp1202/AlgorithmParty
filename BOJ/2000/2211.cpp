// baekjoon 2211 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N=1001;
const int MAX_INF=2e9;

typedef pair<int,int> P;

int N, M, u, v, w, dist[MAX_N];
vector<P> adj[MAX_N];
vector<P> node;
bool visited[MAX_N];

void dfs(int here) {
	visited[here]=true;
	for (int i=0; i<adj[here].size(); i++) {
		int nx = adj[here][i].first;
		int nw = adj[here][i].second;
		if (visited[nx]) continue;
		if (dist[nx] == dist[here] + nw) {
			node.push_back(P(here,nx));
			dfs(nx);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(P(v,w));
		adj[v].push_back(P(u,w));
	}

	fill(dist, dist+N+1, MAX_INF);
	dist[1] = 0;
	priority_queue<P, vector<P>, greater<P> > PQ;
	PQ.push(P(0, 1));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		
		if (visited[curr]) break;
		visited[curr]=true;

		for (int i=0; i<adj[curr].size(); i++) {
			int nx = adj[curr][i].first;
			int nw = adj[curr][i].second;
			if (dist[nx] > dist[curr] + nw) {
				dist[nx] = dist[curr] + nw;
				PQ.push(P(dist[nx], nx));
			}
		}
	}
	
	fill(visited, visited+N+1, false);
	dfs(1);
	printf("%d\n", node.size());
	for (int i=0; i<node.size(); i++)
		printf("%d %d\n", node[i].first, node[i].second);
	return 0;
}
