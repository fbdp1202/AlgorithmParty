// baekjoon 2638 yechan
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=101;
const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int N, M, board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int num;
int t;
vector<pair<int,int> > cheeze;

// (x,y) have air ? , visited[x][y] = 3
void fillAir(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return;
	if (board[x][y]) return;
	if (visited[x][y]) return;

	visited[x][y] = 3;
	for (int d=0; d<4; d++) {
		fillAir(x + dir[d][0], y + dir[d][1]);
	}
}

void dfs(int x, int y) {
	if (visited[x][y]) return;

	visited[x][y]=1;
	// (x,y) = cheeze
	int cnt = 0;
	for (int d=0; d<4; d++) {
		int nx = x + dir[d][0], ny = y + dir[d][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny] == 3) cnt++;
	}

	if (cnt >= 2) {
		board[x][y]=0;
		num--;
	}

	for (int d=0; d<4; d++) {
		int nx = x + dir[d][0], ny = y + dir[d][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (!board[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int findTime()
{
	if (!num) return 0;

	t=0;
	while (num) {
		memset(visited, 0, sizeof(visited));

		fillAir(0,0);

		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++)
				if (!visited[i][j] && board[i][j])
					dfs(i, j);
		t++;
	}
	return t;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j]) num++;
		}
	}
	printf("%d\n", findTime());
	return 0;
}