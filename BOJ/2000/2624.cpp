// baekjoon 2624 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int MAX_N=101;
const int MAX_T=10001;

int T, N, dp[MAX_N][MAX_T];
P coin[MAX_N];

int dfs(int here, int count) {
	if (count > T) return 0;
	if (count == T) return 1;
	if (here == N) return 0;
	int &ret = dp[here][count];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=0; i<=coin[here].second; i++)
		ret += dfs(here+1, count + coin[here].first*i);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &coin[i].first, &coin[i].second);

	printf("%d\n", dfs(0, 0));
	return 0;
}