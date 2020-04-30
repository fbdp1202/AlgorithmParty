// baekjoon 2253 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;
const int MAX_INC=150;
const int MAX_INF=1e9;

int N, M, dp[MAX_N][MAX_INC];
bool visited[MAX_N];

int dfs(int here, int inc) {
	if (here > N) return MAX_INF;
	if (visited[here]) return MAX_INF;
	if (here == N) return 0;
	int &ret = dp[here][inc];
	if (ret != -1) return ret;

	ret = MAX_INF;
	if (inc > 1) ret = min(ret, dfs(here + inc - 1, inc - 1)+1);
	if (inc) ret = min(ret, dfs(here + inc, inc)+1);
	ret = min(ret, dfs(here + inc + 1, inc + 1)+1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int x; scanf("%d", &x);
		visited[x]=true;
	}
	int ret = dfs(1, 0);
	printf("%d\n", ret == MAX_INF ? -1 : ret);
	return 0;
}