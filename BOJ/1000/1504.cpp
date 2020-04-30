// baekjoon 1504 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
const int MAX_N = 800;
const int INF = 1e9;
typedef pair<int,int> P;

int N, V, S1, S2;
vector<vector<P> > adj;
vector<vector<int> > dist;
vector<vector<bool> > visited;

void Dijkstra(int s, int idx) {
	priority_queue<P, vector<P>, greater<P> > PQ;
	dist[idx][s]=0;
	PQ.push(P(0,s));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[idx][curr]);
		if (visited[idx][curr]) return;
		visited[idx][curr]=true;
		for (P &p: adj[curr]) {
			int next=p.first, d=p.second;
			if (dist[idx][next] > dist[idx][curr] + d) {
				dist[idx][next] = dist[idx][curr] + d;
				PQ.push(P(dist[idx][next], next));
			}
		}
	}
}

int main(){
	scanf("%d%d", &N, &V);
	adj.resize(N);
	dist.resize(3,vector<int>(N, INF));
	visited.resize(3,vector<bool>(N,false));

	while (V--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u-1].push_back(P(v-1, w));
		adj[v-1].push_back(P(u-1, w));
	}
	scanf("%d%d", &S1, &S2); S1--, S2--;
	Dijkstra(0, 0);
	Dijkstra(S1, 1);
	Dijkstra(S2, 2);
	int ret = min(INF, min(INF,dist[0][S1]+dist[1][S2])+dist[2][N-1]);
	ret = min(ret, min(ret,dist[0][S2]+dist[2][S1])+dist[1][N-1]);
	if (ret == INF) puts("-1");
	else printf("%d\n", ret);

	return 0;
}