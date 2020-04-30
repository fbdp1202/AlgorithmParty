// baekjoon 16395 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[31][31];

ll paskal(int n, int k) {
	if (dp[n][k]) return dp[n][k];
	if (n == k || k == 1)
		dp[n][k]=1;
	else
		dp[n][k] = paskal(n-1, k-1) + paskal(n-1, k);
	return dp[n][k];
}

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	printf("%lld\n", paskal(N, K));
}