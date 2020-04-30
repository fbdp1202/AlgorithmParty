// baekjoon 1480 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=14;
const int SIZE=(1<<14);
const int MAX_M=11;
const int MAX_C=21;

int N, M, C;
int dp[SIZE][MAX_M][MAX_C];
int jew[MAX_N];

int dfs(int here, int m, int c) {
	int &ret = dp[here][m][c];
	if (ret != -1) return ret;
	if (m == 0) return ret = 0;
	if (c == 0) return ret = dfs(here, m-1, C);

	ret = dfs(here, m-1, C);
	for (int i=0; i<N; i++)
		if (!(here & 1<<i) && jew[i] <= c)
			ret = max(ret, dfs(here | (1<<i), m, c-jew[i])+1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &N, &M, &C);
	for (int i=0; i<N; i++)
		scanf("%d", &jew[i]);
	printf("%d\n", dfs(0,M,C));
	return 0;
}