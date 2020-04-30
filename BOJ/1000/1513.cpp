// baekjoon 1513 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;
const int MAX_C=51;
const int DIV_NUM=1000007;

int N, M, C;
int board[MAX_N][MAX_N];
int dp[MAX_C][MAX_C][MAX_N][MAX_N];

int dfs(int num, int here, int x, int y) {
	if (x > N || y > M) return 0;
	if (board[x][y]) {
		if (here < board[x][y]) {
			num--;
			here = board[x][y];
		}
		else return 0;
	}
	if (num < 0) return 0;
	if (x == N && y == M) return !num;

	int &ret = dp[num][here][x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret += dfs(num, here, x+1, y);
	ret += dfs(num, here, x, y+1);
	ret %= DIV_NUM;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &N, &M, &C);
	for (int i=1; i<=C; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		board[x][y]=i;
	}
	for (int i=0; i<=C; i++)
		printf("%d ", dfs(i, 0, 1, 1));
	puts("");
	return 0;
}