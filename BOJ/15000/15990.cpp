#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=100001;
const ll DIV_NUM=1000000009;

int T, N;
ll dp[MAX_N][4];

int main() {
	dp[1][1]=dp[2][2]=dp[3][3]=dp[3][1]=dp[3][2]=1;
	for (int i=4; i<MAX_N; i++) {
		for (int j=1; j<=3; j++) {
			for (int k=1; k<=3; k++)
				dp[i][j] += dp[i-j][k];
			dp[i][j] -= dp[i-j][j];
			dp[i][j] %= DIV_NUM;
		}
	}

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", (dp[N][1]+dp[N][2]+dp[N][3])%DIV_NUM);
	}
	return 0;
}