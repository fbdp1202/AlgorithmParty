// baekjoon 2329 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=51;
const int MAX_K=129;

int N, K;
ll dp[MAX_N][MAX_K];

ll dfs(int n, int k) {
	if (k < 0) return 0;
	if (n == 1) return k == 1;
	ll &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	ret = dfs(n-1, k-1) + dfs(n-1, k)*(n-1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &K);

	for (int i=0; i<=128; i++)
		printf("%d: %lld\n", i, dfs(50, i));
	return 0;
}