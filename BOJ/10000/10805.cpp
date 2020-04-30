// baekjoon 10805 yechan
#include <bits/stdc++.h>
using namespace std;
const int MAX_INF=1e9;

int dp[51][51][51][51];

int dfs(int h1, int w1, int h2, int w2) {
	// printf("dfs(%d, %d, %d, %d)\n",h1,w1,h2,w2);
	int &ret = dp[h1][w1][h2][w2];
	if (ret != -1) return ret;
	ret = MAX_INF;

	for (int i=1; i<w2; i++)
		ret = min(ret, dfs(h1, w1-i, h2, w2-i) + dfs(h1-h2, i, 0, 0));
	if (w2) ret = min(ret, dfs(h1, w1-w2, 0, 0) + dfs(h1-h2, w2, 0, 0));
	for (int i=w2+1; i<w1; i++)
		ret = min(ret, dfs(h1, w1-i, 0, 0) + dfs(h1, i, h2, w2));

	for (int i=1; i<h2; i++)
		ret = min(ret, dfs(h1-i, w1, h2-i, w2) + dfs(i, w1-w2, 0, 0));
	if (h2) ret = min(ret, dfs(h2, w1-w2, 0, 0) + dfs(h1-h2, w1, 0, 0));
	for (int i=h2+1; i<h1; i++)
		ret = min(ret, dfs(i, w1, h2, w2) + dfs(h1-i, w1, 0, 0));

	dp[w1][h1][w1][h2]=ret;
	return ret;
}

int main() {
	int h1, w1, h2, w2;
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d%d", &h1, &w1, &h2, &w2);
	for (int i=1; i<=50; i++)
		dp[i][i][0][0] = 1;
	printf("%d\n", dfs(h1,w1,h2,w2));
	return 0;
}