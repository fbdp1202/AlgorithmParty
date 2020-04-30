// baekjoon 10273 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> P;
const int MAX_N=20001;
const int MIN_INF=-2e9;

int T, N, E, cave[MAX_N], ret;
vector<vector<P> > adj;
int cost[MAX_N];
queue<int> path;
int dret;

int dfs(int here) {
	int &ret = cost[here]; 
	if (ret != MIN_INF) return ret;

	ret = 0;
	for (int i=0; i<adj[here].size(); i++)
		ret = max(ret, dfs(adj[here][i].first) - adj[here][i].second);

	return ret = ret + cave[here];
}

void findroot(int here, int money) {
	path.push(here);
	money -= cave[here];
	if (!money) {
		return;
	}

	for (int i=0; i<adj[here].size(); i++) {
		int nx = adj[here][i].first;
		int c = adj[here][i].second;
		if (cost[nx] - c == money) {
			findroot(nx, money + c);
			return;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		fill(cost, cost+MAX_N, MIN_INF);
		scanf("%d%d", &N, &E);
		adj = vector<vector<P> >(N+1);
		for (int i=1; i<=N; i++)
			scanf("%d", &cave[i]);

		for (int i=0; i<E; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back(P(b, c));
		}

		ret = dfs(1);
		findroot(1, ret);
		printf("%d %d\n", ret, path.size());
		while (!path.empty()) {
			printf("%d ", path.front());
			path.pop();
		}
		puts("");
	}
	return 0;
}