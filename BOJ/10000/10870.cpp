// baekjoon 10870 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int dp[22];

int main()
{
	scanf("%d", &N);
	dp[0]=0, dp[1]=1, dp[2]=1;
	for (int i=3; i<=N; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	printf("%d\n", dp[N]);
	return 0;
}