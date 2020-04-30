// baekjoon 16194 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1111;
const int MAX_INF=2e9;

int N, card[MAX_N], dp[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &card[i]);


	for (int i=1; i<=N; i++) {
		int ret = MAX_INF;
		for (int j=1; j<=i; j++)
			ret = min(ret, dp[i-j] + card[j]);
		dp[i] = ret;
	}
	printf("%d\n", dp[N]);
	return 0;
}