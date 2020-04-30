// baekjoon 1005 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int T, N, K, X, Y, to, cost[MAX_N], dp[MAX_N];
bool need[MAX_N][MAX_N];

int findDP(int p) {
	if(~dp[p]) return dp[p];

	int tmp = 0;
	for (int i=1; i<=N; i++)
		if(need[p][i])
			tmp = max(tmp, findDP(i));

	dp[p] = tmp+cost[p];
	return dp[p];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		for (int i=1; i<=N; i++) for (int j=1; j<=N; j++)
			need[i][j]=false;
		fill(dp, dp+MAX_N, -1);

		for (int i=1; i<=N; i++)
			scanf("%d", &cost[i]);

		while (K--) {
			scanf("%d %d", &X, &Y);
			need[Y][X]=true;
		}
		scanf("%d", &to);

		printf("%d\n", findDP(to));
	}
	return 0;
}