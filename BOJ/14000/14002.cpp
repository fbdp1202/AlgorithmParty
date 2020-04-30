// baekjoon 14002 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1001;

int N, data[MAX_N], dp[MAX_N], index[MAX_N], pindex[MAX_N];

void dfs(int h) {
	if (!h) return;
	dfs(pindex[h]);
	printf("%d ", data[h]);
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", data + i);
	for (int i=1; i<=N; i++) {
		dp[i] = 1e9;
		int p = lower_bound(dp + 1, dp + 1 + i, data[i]) - dp;
		dp[p] = data[i];
		index[p] = i;
		pindex[i] = index[p-1];
	}
	int sz = lower_bound(dp + 1, dp + 1 + N, 1e9) - dp - 1;
	printf("%d\n", sz);
	dfs(index[sz]);
	return 0;
}