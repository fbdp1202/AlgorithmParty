// baekjoon #include <cstdio>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX_N 500
#define MAX_INF 987654321

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int ans, N, M, board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void dfs(int x, int y, int block, int curr_sum) {
	if (block == 4) {
		ans = max(ans, curr_sum);
		return;
	}

	visited[x][y]=true;

	for (int d=0; d<4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (!visited[nx][ny])
			dfs(nx, ny, block+1, curr_sum + board[x][y]);
	}
	visited[x][y]=false;
}

void CheckExceptShape(int x, int y) {
	int minValue = MAX_INF;
	int result = board[x][y];
	int cnt = 0;
	for (int d=0; d < 4; d++)
	{
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		cnt++;
		result += board[nx][ny];
		if (minValue > board[nx][ny])
			minValue = board[nx][ny];
	}

	if (cnt == 4)
		result -= minValue;

	ans = max(ans, result);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			scanf("%d", &board[i][j]);

	for (int i=0; i<N; i++) { // x position
		for (int j=0; j<M; j++) {  	// y position
			dfs(i, j, 0, 0);
			CheckExceptShape(i, j);
		}
	}
	printf("%d\n", ans);

	return 0;
}