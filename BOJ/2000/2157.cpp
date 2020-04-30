// baekjoon 2157 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=301;
const int MIN_INF=-1e9;

int N, M, K;
int dp[MAX_N][MAX_N];
vector<P> adj[MAX_N];

int dfs(int here, int num) {
	if (num > M) return MIN_INF;
	if (here == N) return 0;
	int &ret = dp[here][num];
	if (ret != -1) return ret;
	ret = MIN_INF;
	for (P &p: adj[here])
		ret = max(ret, dfs(p.first, num+1) + p.second);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &N, &M, &K);
	for (int i=0; i<K; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if (u > v) continue;
		adj[u].push_back(P(v, w));
	}
	printf("%d\n", dfs(1, 1));
	return 0;
}