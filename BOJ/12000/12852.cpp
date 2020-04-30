// baekjoon 12852 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=1000001;
const int MAX_INF=2e9;

int N;
int dp[MAX_N];

int dfs(int here) {
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = MAX_INF;
	if (here % 3 == 0) ret = min(ret, dfs(here/3)+1);
	if (here % 2 == 0) ret = min(ret, dfs(here/2)+1);
	ret = min(ret, dfs(here-1)+1);
	return ret;
}

void tracking(int here) {
	printf("%d ", here);
	if (here == 1) return;

	if (here % 3 == 0) {
		if (dp[here] == dp[here/3] + 1) {
			tracking(here/3);
			return;
		}
	}
	if (here % 2 == 0) {
		if (dp[here] == dp[here/2] + 1) {
			tracking(here/2);
			return;
		}
	}
	tracking(here - 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);

	dp[1] = 0;
	printf("%d\n", dfs(N));
	tracking(N);
	puts("");
	return 0;
}