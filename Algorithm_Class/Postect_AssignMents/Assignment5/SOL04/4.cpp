// postech Assignment5. 3.cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=301;
const ll MAX_INF=(ll)1e12;
int t, N, x, point[MAX_N];

ll ans, dp[2][MAX_N][MAX_N]; // [0:1(down:up)][index of Points]

ll dfs(int down, int up, int here, int state) {
	if (here == N) return abs(point[here] - point[down]) + abs(point[here] - point[up]);
	ll &ret = dp[state][down][up];
	if (ret) return ret;
	ret = MAX_INF;
	ret = min(ret, dfs(down, here, here+1, 1) + abs(point[here]-point[up])); // here set up
	ret = min(ret, dfs(here, up, here+1, 0) + abs(point[here]-point[down])); // here set down
	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		ans = 0;
		scanf("%d", &N);
		for (int i=1; i<=N; i++)
			scanf("%d%d", &x, &point[i]);
		ans += x*2;
		ans += dfs(0, 0, 0, 0);
		printf("%lld\n", ans);
	}
	return 0;
}