// baekjoon 2294 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 101
#define MAX_K 10001
#define INF 987654321
int N, K, money[MAX_N], dp[MAX_N][MAX_K];

int useMoney(int n, int k)
{
	if(n == N && k == 0) return 0;
	if(n == N && k != 0) return INF;
	if(dp[n][k] != - 1) return dp[n][k];

	int result = useMoney(n+1,k);
	if(k >= money[n])
		result = min(result, useMoney(n, k-money[n])+1);

	dp[n][k] = result;
	return result;
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", &money[i]);

	for(int i=0; i<=N; i++)
		for(int j=0; j<=K; j++)
			dp[i][j] = -1;

	int result = useMoney(0,K);
	if(result == INF) printf("-1");
	else printf("%d\n", result);
}