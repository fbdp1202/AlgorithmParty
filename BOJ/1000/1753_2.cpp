// baekjoon 1753 yechan
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 20001;
const int MAX_E = 300001;
const int INF = 1e9;
typedef pair<int,int> P;
int V, E, S;
vector<int> dist;
vector<bool> visited;
vector<vector<P> > adj;

int main(){
	scanf("%d%d", &V, &E);
	scanf("%d", &S);
	S--;
	adj.resize(V);
	dist.resize(V, INF);
	visited.resize(V, false);

	while (E--) {
		int u, v, w;
		scanf("%d%d%d",&u, &v, &w);
		adj[u-1].push_back({v-1, w});
	}

	priority_queue<P, vector<P>, greater<P>> pq;
	dist[S] = 0;
	pq.push(P(0,S));
	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curr]);
		if (visited[curr]) break;
		visited[curr]=true;
		for (auto &p: adj[curr]) {
			int next = p.first, d = p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push(P(dist[next], next));
			}
		}
	}

	for (int i=0; i<V; i++) {
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
	return 0;
}