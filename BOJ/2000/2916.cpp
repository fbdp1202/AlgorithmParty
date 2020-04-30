// baekjoon 2916 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=11;
const int MAX_DEGREE=360;
int N, K, degree[MAX_N];
bool dp[MAX_N][MAX_DEGREE];

void dfs(int here, int val) {
	if (here == N) return;
	if (dp[here][val]) return;
	dp[here][val]=true;
	int next = (360 + degree[here] + val)%360;
	if (!dp[here][next]) dfs(here, next);
	next = (360 - degree[here] + val)%360;
	if (!dp[here][next]) dfs(here, next);
	dfs(here+1, val);
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		scanf("%d", &degree[i]);

	dfs(0,0);

	while (K--) {
		int x;
		scanf("%d", &x);
		puts(dp[N-1][x] ? "YES" : "NO");
	}

	return 0;
}