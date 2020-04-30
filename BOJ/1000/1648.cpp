// baekjoon 1648 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 14;
const int MAX_SIZE = (1<<MAX_N);
const int DIV_NUM = 9901;

int N, M;
int dp[MAX_N][MAX_SIZE][MAX_N];

int dfs(int here, int bitmask, int start) {
	if (here >= N) return 0;
	if (bitmask == (1<<M)-1) {
		if (here == N-1) return 1;
		return dfs(here+1, 0, 0);
	}

	int &ret = dp[here][bitmask][start];
	if (ret != -1) return ret;
	ret = 0;
	ret = (ret + dfs(here+1, (~bitmask) & ((1<<M) - 1), 0)) % DIV_NUM;
	for (int i=start; i<M-1; i++) {
		if ((bitmask & (1<<i)) || (bitmask & (1<<(i+1)))) continue;
		ret = (ret + dfs(here, bitmask|(1<<i)|(1<<(i+1)), i+2)) % DIV_NUM;
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &M);
	printf("%d\n", dfs(0, 0, 0));
	return 0;
}