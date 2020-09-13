// baekjoon 14916 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;
const int MAX_INF=1e9;

int dp[MAX_N];

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;

	ret = MAX_INF;
	if (here >= 5) ret = min(ret, dfs(here-5)+1);
	if (here >= 2) ret = min(ret, dfs(here-2)+1);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0]=0;
	scanf("%d", &N);
	int ret = dfs(N);
	if (ret == MAX_INF) ret = -1;
	printf("%d\n", ret);
	return 0;
}