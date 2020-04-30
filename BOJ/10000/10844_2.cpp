// baekjoon 10844_2 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int DIV_NUM=1e9;

int N;
ll dp[10][2];

int main() {
	scanf("%d", &N);
	for (int i=1; i<10; i++)
		dp[i][1]=1;

	for (int i=1; i<N; i++) {
		for (int j=0; j<10; j++) {
			if (j-1 >= 0) dp[j-1][(i&1)^1] += dp[j][i&1];
			if (j+1 < 10) dp[j+1][(i&1)^1] += dp[j][i&1];
		}
		for (int j=0; j<10; j++) {
			dp[j][(i&1)^1]%=DIV_NUM;
			dp[j][i&1]=0;
		}
	}

	ll ret = 0;
	for (int j=0; j<10; j++)
		ret += dp[j][(N&1)];
	printf("%lld\n", ret%DIV_NUM);
	return 0;
}