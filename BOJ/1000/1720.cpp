// baekjoon 1720 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=31;
typedef long long ll;
int N;
ll dp[MAX_N];

int main(void) {
	dp[0]=1; dp[1]=1; dp[2]=3;
	for (int i=3; i<31; i++)
		dp[i]=dp[i-1]+(dp[i-2]<<1);
	scanf("%d", &N);
	if (N < 2) return !printf("%lld\n", dp[N]);
	if (N&1) printf("%lld\n", (dp[N]+dp[N>>1])>>1);
	else printf("%lld\n", (dp[N]+dp[N>>1]+(dp[(N-2)>>1]<<1))>>1);
	return 0;
}