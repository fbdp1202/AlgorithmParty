// baekjoon 2315 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,ll>;

const int MAX_N=1001;
const int MAX_D=1001;
const ll MAX_INF=(1LL<<62);

int N, M;
P lamp[MAX_N];
ll sum[MAX_N];
ll dp[MAX_N][MAX_N][2];

ll dfs(int L, int R, int D) {
	if (L == 1 && R == N) return 0;
	ll &ret = dp[L][R][D];
	if (ret != -1) return ret;
	ret = MAX_INF;
	int cur = (D == 0) ? lamp[L].first:lamp[R].first;
	if (L != 1) ret = min(ret, dfs(L-1, R, 0)+(sum[N]-(sum[R]-sum[L-1]))*abs(cur-lamp[L-1].first));
	if (R != N) ret = min(ret, dfs(L, R+1, 1)+(sum[N]-(sum[R]-sum[L-1]))*abs(cur-lamp[R+1].first));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++) {
		scanf("%d%lld", &lamp[i].first, &lamp[i].second);
		sum[i]=sum[i-1]+lamp[i].second;
	}
	printf("%lld\n", dfs(M,M,0));
	return 0;
}