// baekjoon 2903 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define SQ(x) (x)*(x)

int dp[16];

int main() {
	int N;
	scanf("%d", &N);
	dp[1] = 3;
	for (int i=2; i<=15; i++) {
		dp[i] = dp[i-1]*2-1;
	}
	printf("%d\n", SQ(dp[N]));
	return 0;
}