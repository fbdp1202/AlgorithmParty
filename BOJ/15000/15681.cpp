// baekjoon 15681 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=100000;

int N, R, Q;
vector<int> adj[MAX_N];
int dp[MAX_N];

int dfs(int here, int parent=-1) {
	int &ret = dp[here];
	if (ret) return ret;
	ret = 1;
	for (int i=0; i<adj[here].size(); i++) {
		int next = adj[here][i];
		if (next == parent) continue;
		ret += dfs(next, here);
	}
	return ret;
}

int main()
{
	scanf("%d%d%d", &N, &R, &Q);
	for (int i=0; i<N-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(R-1);
	for (int i=0; i<Q; i++) {
		int x;
		scanf("%d", &x);
		printf("%d\n", dp[x-1]);
	}
	return 0;
} 