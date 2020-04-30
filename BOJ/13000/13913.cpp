// baekjoon 13913 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=200001;
const int MAX_INF=2e9;

int N, K, dp[MAX_N];

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;

	ret = MAX_INF;
	if (K < here) {
		ret = min(ret, dfs(here-1) + 1);
	} else {
		ret = min(ret, dfs(here*2) + 1);
		ret = min(ret, dfs(here+1) + 1);
		if (here > 0) ret = min(ret, dfs(here-1) + 1);
	}
	return ret;
}

void tracking(int here) {
	printf("%d ", here);
	if (here == K) return;

	if (here > 0 && dp[here] == dp[here-1] + 1) {
		tracking(here - 1);
		return;
	}
	if (dp[here] == dp[here*2] + 1) {
		tracking(here * 2);
		return;
	}
	if (dp[here] == dp[here+1] + 1) {
		tracking(here + 1);
		return;
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &K);

	dp[K] = 0;
	printf("%d\n", dfs(N));
	tracking(N);
	puts("");
	return 0;
}