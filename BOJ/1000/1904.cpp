// baekjoon 1904 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000001
#define DIV_NUM 15746
int N, dp[MAX_N];

int main()
{
	scanf("%d", &N);
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=N; i++){
		dp[i] += dp[i-1] + dp[i-2];
		dp[i] %= DIV_NUM;
	}
	printf("%d", dp[N]%DIV_NUM);
	return 0;
}