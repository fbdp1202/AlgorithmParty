// baekjoon 1660 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=262;
const int MAX_V=300001;

int N, coin[MAX_N], dp[MAX_V];

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;

	ret = MAX_V;
	for (int i=1; i<MAX_N; i++) {
		if (here < coin[i]) break;
		ret = min(ret, dfs(here - coin[i])+1);
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	scanf("%d", &N);
	int cur = 0;
	for (int i=1; i<MAX_N; i++) {
		cur += i;
		coin[i] = coin[i-1]+cur;
	}

	dp[0]=0;
	printf("%d\n", dfs(N));
	return 0;
}