// baekjoon 14863 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;
const int MAX_K=100001;

int N, K, dp[MAX_N][MAX_K], dist[MAX_N][2], money[MAX_N][2], ret;

int main() {
	scanf("%d%d", &N, &K);
	for (int i=1; i<=N; i++)
		for (int j=0; j<2; j++)
			scanf("%d%d", &dist[i][j], &money[i][j]);

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=K; j++) {
			if (j-dist[i][0] >= 0 && (dp[i-1][j-dist[i][0]] || i==1))
				dp[i][j] = max(dp[i][j], dp[i-1][j-dist[i][0]] + money[i][0]);
			if (j-dist[i][1] >= 0 && (dp[i-1][j-dist[i][1]] || i==1))
				dp[i][j] = max(dp[i][j], dp[i-1][j-dist[i][1]] + money[i][1]);
		}
	}

	for (int j=0; j<=K; j++)
		ret = max(ret, dp[N][j]);
	printf("%d\n", ret);
	return 0;
}