// baekjoon 1520 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 502
#define INF 1e9
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int N, M, data[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int backtracking(int x, int y) {
	if (x == N && y == M) return 1;
	if (~dp[x][y]) return dp[x][y];

	int rst = 0;
	for (int d = 0; d < 4; ++d) {
		int nx = dx[d] + x, ny = dy[d] + y;
		if (data[nx][ny] && data[nx][ny] < data[x][y])
			rst += backtracking(nx, ny);
	}
	return dp[x][y] = rst;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &data[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", backtracking(1, 1));
	return 0;
}