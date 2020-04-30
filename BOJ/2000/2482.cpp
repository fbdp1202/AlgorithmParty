// baekjoon 2482 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll DIV_NUM=1e9+3;

const int MAX_N=1001;

int N, K;
ll dp[MAX_N][MAX_N];

ll dfs(int color, int choose) {
	if (choose == 0) return 1;
	if (color < choose*2 - 1) return 0;

	ll &ret = dp[color][choose];
	if (ret != -1) return ret;
	ret = (dfs(color-1, choose)+dfs(color-2, choose-1))%DIV_NUM;
	return ret;
}

ll start(int color, int choose) {
	return (dfs(color-3, choose-1) + dfs(color-1, choose))%DIV_NUM;
}

int main() {
	for (int i=0; i<MAX_N; i++)
		fill(dp[i], dp[i]+MAX_N, -1);
	scanf("%d%d", &N, &K);
	dp[1][1]=1;
	printf("%lld\n", start(N, K));
	return 0;
}