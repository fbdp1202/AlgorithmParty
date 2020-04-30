// baekjoon 9084 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 21
#define MAX_M 10001
int N, T, M, coin[MAX_N];
int dp[MAX_M];

int main()
{
	scanf("%d", &T);
	for(int i=0; i<T; i++)
	{
		fill(dp, dp+MAX_M, 0);
		fill(coin, coin+MAX_N, 0);
		scanf("%d", &N);
		for(int j=1; j<=N; j++)
			scanf("%d", &coin[j]);
		scanf("%d", &M);
		for(int j=1; j<=N; j++){
			dp[coin[j]]++;
			for(int z=coin[j]+1; z<=M; z++){
				dp[z] += dp[z - coin[j]];
			}
		}
		printf("%d\n", dp[M]);
	}
}