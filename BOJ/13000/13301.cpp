// baekjoon 13301 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
long long dp[82];

int main()
{
	dp[1]=dp[2]=1;
	dp[3]=2, dp[4]=3;

	scanf("%d", &N);
	for (int i=5; i<=N+1; i++)
		dp[i] = dp[i-1]+dp[i-3]+dp[i-4];

	printf("%lld\n", dp[N]*2+dp[N+1]*2);
	return 0;
}