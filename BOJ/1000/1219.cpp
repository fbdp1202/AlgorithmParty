// baekjoon 1219 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=101;
const long long MAX_INF=1LL<<60;

int N, S, E, M, city[MAX_N];
bool cycle[MAX_N];
long long dist[MAX_N];
vector<pair<int, int> > adj[MAX_N];

void dfs(int here) {
	cycle[here] = true;
	for (int i=0; i<adj[here].size(); i++) {
		int nx = adj[here][i].first;
		if (cycle[nx]) continue;
		dfs(nx);
	}
}

int main() {
	scanf("%d%d%d%d", &N, &S, &E, &M);
	while (M--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	for (int i=0; i<N; i++)
		scanf("%d", &city[i]);

	fill(dist, dist+N, MAX_INF);

	dist[S] = -city[S];
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (dist[j] == MAX_INF) continue;
			for (int k=0; k<adj[j].size(); k++) {
				int nx = adj[j][k].first;
				int nw = adj[j][k].second;
				if (dist[nx] > dist[j] + nw - city[nx]) {
					dist[nx] = dist[j] + nw - city[nx];
					if (i == N - 1) {
						dfs(nx);
					}
				}
			}
		}
	}

	if (dist[E] == MAX_INF) {
		printf("gg\n");
	}
	else if (cycle[E]) {
		printf("Gee\n");
	} else {
		printf("%lld\n", -dist[E]);
	}

	return 0;
}