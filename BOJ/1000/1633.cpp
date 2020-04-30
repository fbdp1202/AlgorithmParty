// baekjoon 1633 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=1001;
const int MIN_INF=-1e9;
typedef pair<int,int> P;

int N;
P data[MAX_N];
int dp[MAX_N][16][16];

int dfs(int here, int black, int white) {
	if (black == 15 && white == 15) return 0;
	if (black > 15 || white > 15 || here == N) return MIN_INF;
	int &ret = dp[here][black][white];
	if (ret != -1) return ret;
	ret = MIN_INF;

	// choice black
	ret = max(ret, dfs(here+1, black+1, white) + data[here].first);

	// choice white
	ret = max(ret, dfs(here+1, black, white+1) + data[here].second);

	// no choice white
	ret = max(ret, dfs(here+1, black, white));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	while (scanf("%d%d", &data[N].first, &data[N].second) != -1) {
		N++;
	}
	N++;
	printf("%d\n", dfs(0, 0, 0));
	return 0;	
}