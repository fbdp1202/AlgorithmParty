// baekjoon 1799 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=11;

int N, board[MAX_N][MAX_N], diag[2][MAX_N*2], ans;

inline bool check(int x, int y) {
	return !diag[0][x+y] && !diag[1][N-1-x+y];
}

inline void mark(int x, int y, int value) {
	diag[0][x+y]=diag[1][N-1-x+y]=value;
}

int dfs(int x, int y) {
	if (x == N) return 0;
	int ret = 0;
	if (board[x][y] && check(x, y)) {
		mark(x, y, 1);
		if (y+2 < N) ret = max(ret, dfs(x, y+2) + 1);
		else ret = max(ret, dfs(x+1, (y+1)%2) + 1);
		mark(x, y, 0);
	}
	if (y+2 < N) ret = max(ret, dfs(x, y+2));
	else ret = max(ret, dfs(x+1, (y+1)%2));

	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	ans = dfs(0, 0);
	ans += dfs(0, 1);

	printf("%d\n", ans);
	return 0;
}