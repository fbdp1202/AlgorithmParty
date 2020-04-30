// postech Assignment5. 1.cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=3001;
const ll MIN_INF=0x8080808080808080;

int T, N, M, board[MAX_N][MAX_N];
ll dp[2][MAX_N][MAX_N]; // dp[(0:left, 1:right)][N][M]

ll dfs(int x, int y, int dir) {
	if (x == N-1 && y == M-1) return board[N-1][M-1];
	ll &ret = dp[dir][x][y];
	if (ret != MIN_INF) return ret;
	ret = MIN_INF;
	if (x < N-1) {
		ret = max(ret, dfs(x+1, y, 0) + board[x][y]); // down left
		ret = max(ret, dfs(x+1, y, 1) + board[x][y]); // down right
	}
	if (!dir && y-1 >= 0) ret = max(ret, dfs(x, y-1, 0) + board[x][y]); // left
	if (dir && y+1 <= M-1) ret = max(ret, dfs(x, y+1, 1) + board[x][y]); // right
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(dp, 0x80, sizeof(dp));
		scanf("%d%d", &N, &M);
		// for (int d=0; d<2; d++) for (int i=0; i<N; i++) for (int j=0; j<M; j++) dp[d][i][j] = MIN_INF;
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++)
				scanf("%d", &board[i][j]);
		printf("%lld\n", dfs(0, 0, 1));
	}
	return 0;
}