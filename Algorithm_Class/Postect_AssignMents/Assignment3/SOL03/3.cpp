// algo 3.cpp
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
const int MAX_M=10001;
const int INF=1e9;

int T, N, M, u, v, ret;
vector<vector<int> > adj;
vector<int> visited;

void dfs(int pos, int dist) {
	visited[pos]=dist;
	for (int &next : adj[pos]) {
		if (!visited[next]) dfs(next, dist+1);
		else if (abs(dist - visited[next]) >= 2) {
			ret = min(ret, abs(dist - visited[next]));
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		adj = vector<vector<int> >(N);
		visited = vector<int>(N, 0);
		ret = INF;
		for (int i=0; i<M; i++) {
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i=0; i<N; i++) {
			if(!visited[i])
				dfs(i, 1);
		}
		if (ret == INF) ret = -1;
		else ret++;
		printf("%d\n", ret);
	}
	return 0;
}