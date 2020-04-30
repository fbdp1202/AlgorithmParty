// baekjoon 1699 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100001;
const int MAX_INF=1e9;
int N, dp[MAX_N];

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = MAX_INF;

	for (int i=1; i*i<here; i++)
		ret = min(ret, dfs(here-i*i)+1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	for (int i=1; i<317; i++)
		dp[i*i]=1;

	scanf("%d", &N);
	printf("%d\n", dfs(N));
	return 0;
}