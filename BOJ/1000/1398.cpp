// baekjoon 1398 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=101;
const int MAX_INF=1e9;

int T, dp[MAX_N];
ll N;

int main() {
	fill(dp, dp+MAX_N, MAX_INF);
	scanf("%d", &T);
	dp[0]=0;
	for (int i=0; i<MAX_N; i++) {
		if (dp[i] == MAX_INF) continue;
		if (i+1<MAX_N) dp[i+1] = min(dp[i+1], dp[i]+1);
		if (i+10<MAX_N) dp[i+10] = min(dp[i+10], dp[i]+1);
		if (i+25<MAX_N) dp[i+25] = min(dp[i+25], dp[i]+1);
	}

	while (T--) {
		scanf("%lld", &N);
		ll ret = 0;
		while (N) {
			ret += dp[N%100];
			N/=100;
		}
		printf("%lld\n", ret);
	}
	return 0;
}