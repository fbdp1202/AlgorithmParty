// baekjoon 2184 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N=1000;
const ll MAX_INF=(1LL<<61);

int N, L;
ll house[MAX_N];
ll dp[MAX_N][MAX_N][2]; // (Leftpos)(Rightpos)(left or right == 0 or 1)

ll dfs(int l, int r, int d) {
	if (l == 0 && r == N-1) return 0;
	ll &ret = dp[l][r][d];
	if (ret != MAX_INF) return ret;
	ret = MAX_INF;
	ll cur = (d == 0) ? house[l]:house[r];
	if (l != 0) ret = min(ret, dfs(l-1, r, 0)+(N-(r-l+1))*abs(cur-house[l-1]));
	if (r != N-1) ret = min(ret, dfs(l, r+1, 1)+(N-(r-l+1))*abs(cur-house[r+1]));
	return ret;
}

int main() {
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<MAX_N; j++)
			dp[i][j][0] = dp[i][j][1] = MAX_INF;

	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++)
		scanf("%lld", &house[i]);
	sort(house, house+N);

	ll ret = MAX_INF;
	for (int s=0; s<N; s++)
		ret = min(ret, dfs(s, s, 0) + N*abs(L-house[s]));
	printf("%lld\n", ret);
	return 0;
}