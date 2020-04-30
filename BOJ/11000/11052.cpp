// baekjoon 11052 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N, dp[MAX_N], card[MAX_N];

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=1; i<=here; i++)
		ret = max(ret, dfs(here-i)+card[i]);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	dp[0]=0;
	for (int i=1; i<=N; i++)
		scanf("%d", &card[i]);
	printf("%d\n", dfs(N));
	return 0;
}