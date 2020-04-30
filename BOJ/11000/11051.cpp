// baekjoon 11051 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;
const int DIV_NUM=10007;

int N, K, dp[MAX_N][MAX_N];

int dfs(int n, int k) {
	if (n == 1) return 1;
	if (n == k) return 1;
	if (k == 0) return 1;
	if (k == 1) return n;

	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = (dfs(n-1, k-1)+dfs(n-1,k))%DIV_NUM;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &K);
	printf("%d\n", dfs(N, K));
	return 0;
}