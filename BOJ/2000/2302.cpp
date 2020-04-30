// baekjoon 2302 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 41

int N, M, previous, tmp;
long long dp[MAX_N];

int main()
{
	long long result = 1;
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for(int i=3; i<=40; i++)
		dp[i] = dp[i-1] + dp[i-2];

	scanf("%d %d", &N, &M);

	for(int i=0; i<M; i++){
		scanf("%d", &tmp);
		result *= dp[tmp-1-previous];
		previous = tmp;
	}
	result *= dp[N-previous];
	printf("%lld\n", result);
}