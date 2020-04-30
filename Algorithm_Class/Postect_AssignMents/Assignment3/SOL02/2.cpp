// algo 2.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, ll> P;

const int MAX_N=30001;
const int MAX_M=1000001;
const ll MAX_INF=0x7FFFFFFFFFFFFFF;

int T, N, M, u, v; 
ll w, ret;
vector<vector<P> > adj;
vector<int> visited;

int dfs(int parent, int cur, int dist) {
	visited[cur]=dist;
	for (auto &next : adj[cur]) {
		if (next.first == parent) continue;
		if (!visited[next.first]) {
			int d = dfs(cur, next.first, dist+1);
			if (dist < d) {
				ret = min(ret, next.second);
			} else {
				visited[cur] = min(d, visited[cur]);
			}
		}
		else {
			visited[cur] = min(visited[cur], visited[next.first]);
		}
	}
	return visited[cur];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		adj = vector<vector<P> >(N);
		visited = vector<int>(N, 0);
		ret = MAX_INF;
		for (int i=0; i<M; i++) {
			scanf("%d%d%lld", &u, &v, &w);
			adj[u].push_back(P(v,w));
			adj[v].push_back(P(u,w));
		}
		dfs(-1, 0, 1);
		if (ret == MAX_INF) ret = -1;
		printf("%lld\n", ret);
	}
	return 0;
}