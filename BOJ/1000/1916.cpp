// baekjoon 1916 yechan
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX_N = 1001;
const int MAX_V = 100001;
typedef pair<int, int> P;

int N, V, S, E;
vector<int> dist;
vector<bool> visited;
vector<vector<P> > adj;

int main(){
	scanf("%d", &N);
	scanf("%d", &V);
	dist.resize(N, INF);
	visited.resize(N, false);
	adj.resize(N);

	while (V--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u-1].push_back(P(v-1,w));
	}

	scanf("%d%d", &S, &E); S--, E--;

	priority_queue<P, vector<P>, greater<P>> PQ;
	dist[S]=0;
	PQ.push(P(0, S));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr]) break;
		visited[curr]=true;
		for (auto &p: adj[curr]) {
			int next=p.first, d=p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	printf("%d\n", dist[E]);
	return 0;
}