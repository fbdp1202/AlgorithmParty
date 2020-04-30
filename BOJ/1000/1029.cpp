// baekjoon 1029 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=15;
const int SIZE=(1<<MAX_N);

int N, dp[MAX_N][SIZE][10], board[MAX_N][MAX_N];

int sold(int here, int state, int cost)
{
	int &ret = dp[here][state][cost];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=0; i<N; i++) {
		if (here == i) continue;
		if ((state>>i) & 1) continue;
		if (cost <= board[here][i]) ret = max(ret, sold(i, state+(1<<i), board[here][i])+1);
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%1d", &board[i][j]);
	printf("%d\n", sold(0, 1, 0)+1);
	return 0;
}