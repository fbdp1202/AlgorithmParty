// baekjoon 1103 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 50
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

char board[MAX_N][MAX_N+1];
int N, M, dp[MAX_N][MAX_N], visited[MAX_N][MAX_N];
bool cycle;

void dfs(int x, int y) {
	visited[x][y] = -1;
	if(board[x][y] == 'H') {
		visited[x][y] = 1;
		return;
	}

	for (int d=0; d<4; d++) {
		int num = board[x][y]-'0';
		int nx = x + dx[d]*num;
		int ny = y + dy[d]*num;
		if (0 <= nx && nx < N &&
			0 <= ny && ny < M) {
			if (visited[nx][ny] == -1) {
				cycle = true;
				return;
			} else if(!visited[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
	visited[x][y] = 1;
}

int PlayGame(int x, int y) {
	if(x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 'H') return 0;
	int &ret=dp[x][y];
	if(ret) return ret;

	ret=1;
	for (int d=0; d<4; d++) {
		int num = board[x][y]-'0';
		int nx = x + dx[d]*num;
		int ny = y + dy[d]*num;
		ret = max(PlayGame(nx, ny) + 1, ret);
	}
	return ret;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) scanf("%s", board[i]);

	dfs(0, 0);
	if (cycle) printf("-1");
	else printf("%d", PlayGame(0,0));
	return 0;
}