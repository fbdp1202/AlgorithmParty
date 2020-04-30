// AssignMent 06 - 3.cpp
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=501;
const int MAX_M=2001;

int T, N, M, u, v, w, ret;
int c[MAX_N][MAX_N], f[MAX_N][MAX_N];
int node[MAX_N];

int main() {
  	scanf("%d", &T);
	while (T--) {
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		scanf("%d%d", &N, &M);
		vector<vector<int> > adj(N);
		for (int i=0; i<N; i++) 
			scanf("%d", &node[i]);
		while (M--) {
			scanf("%d%d%d", &u, &v, &w);
			c[u][v] += w;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ret = 0;
		while (1) {
			vector<int> pv(N, -1);
			queue<int> Q;
			Q.push(0);
			while (!Q.empty() && pv[N-1] == -1) {
				int cur = Q.front();
				Q.pop();
				if (!node[cur]) continue;
				for (int i=0; i<adj[cur].size(); i++) {
					int nx = adj[cur][i];
					if (c[cur][nx] - f[cur][nx] <= 0) continue;
					if (!node[nx]) continue;
					if (pv[nx] != -1) continue;
					Q.push(nx);
					pv[nx] = cur;
					if (nx == N-1) break;
				}
			}
			if (!node[N-1]) break;
			if (pv[N-1] == -1) break;

			int minFlow = 1e9;
			for (int i=N-1; i!=0; i=pv[i])
				minFlow = min(minFlow, min(c[pv[i]][i]-f[pv[i]][i], node[i]));
			minFlow = min(minFlow, node[0]);
			for (int i=N-1; i!=0; i=pv[i]) {
				node[i] -= minFlow;
				f[pv[i]][i] += minFlow;
				f[i][pv[i]] -= minFlow;
			}
			node[0] -= minFlow;
			ret += minFlow;
		}
		printf("%d\n", ret);
	}
	return 0;
}