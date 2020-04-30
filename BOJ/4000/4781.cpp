// baekjoon 4781 yechan
#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int, int>;

const int MAX_N=5000;
const int MAX_M=10001;

Pii candy[MAX_N];
int N, M, dp[MAX_M];
double dM;

int dfs(int here) {
	if (here == 0) return 0;
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=0; i<N; i++) {
		if (here < candy[i].second) continue;
		ret = max(ret, dfs(here-candy[i].second) + candy[i].first);
	}
	return ret;
}

int main() {
	while (1) {
		scanf("%d %lf", &N, &dM);
		M = (int)(dM*100);
		if (N == 0 && M == 0) break;
		for (int i=0; i<N; i++) {
			int x; double y;
			scanf("%d %lf", &x, &y);
			candy[i] = Pii(x, int(y*100 + 0.5));
		}
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		printf("%d\n", dfs(M));
	}
	return 0;
}