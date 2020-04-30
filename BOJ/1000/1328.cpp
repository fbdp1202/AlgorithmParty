// baekjoon 1328 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=101;
const ll DIV_NUM=1000000007;
const ll MAX_INF=(1LL<<62);

int N, L, R;
ll dp[MAX_N][MAX_N][MAX_N];

ll dfs(int n, int l, int r) {
	if (l == 0 || r == 0) return 0;
	if (n == 1) return l == 1 && r == 1;
	ll &ret = dp[n][l][r];
	if (ret != MAX_INF) return ret;
	return ret = (dfs(n-1, l-1, r) + dfs(n-1, l, r-1) + (n-2)*dfs(n-1, l, r))%DIV_NUM;
}

int main() {
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<MAX_N; j++)
			for (int k=0; k<MAX_N; k++)
				dp[i][j][k]=MAX_INF;
	scanf("%d%d%d", &N, &L, &R);
	printf("%lld\n", dfs(N,L,R));
	return 0;
}