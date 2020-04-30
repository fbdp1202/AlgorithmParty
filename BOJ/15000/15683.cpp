// baekjoon 15683 yechan
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

const int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

int ret = 0;
int area = 0;
int N, M, K, board[9][9];
vector<P> cctv;
int visited[9][9];

void fillBoard(int x, int y, int d, int cnt) {
	int nx = x;
	int ny = y;
	while (1) {
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
		if (board[nx][ny] == 6) return;

		if (!visited[nx][ny]) visited[nx][ny]=cnt, area++;
		nx += dir[d][0];
		ny += dir[d][1];
	}
}

void fillBoardAll(int x, int y) {
	for (int d=0; d<4; d++)
		fillBoard(x, y, d, 1);
}

void eraseBoard(int x, int y, int d, int cnt) {
	int nx = x;
	int ny = y;
	while (1) {
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
		if (board[nx][ny] == 6) return;

		if (visited[nx][ny] == cnt) visited[nx][ny]=0, area--;
		nx += dir[d][0];
		ny += dir[d][1];
	}
}

void dfs(int here, int cnt) {
	if (here == K) {
		ret = max(ret, area);
		return;
	}
	int x = cctv[here].first;
	int y = cctv[here].second;
	int nx, ny;
	if (board[x][y] == 1) {
		for (int d=0; d<4; d++) {
			fillBoard(x, y, d, cnt);
			dfs(here+1, cnt+1);
			eraseBoard(x, y, d, cnt);
		}
	}
	if (board[x][y] == 2) {
		for (int d=0; d<2; d++) {
			fillBoard(x, y, d, cnt);
			fillBoard(x, y, (d+2)%4, cnt);
			dfs(here+1, cnt+1);
			eraseBoard(x, y, (d+2)%4, cnt);
			eraseBoard(x, y, d, cnt);
		}
	}
	if (board[x][y] == 3) {
		for (int d=0; d<4; d++) {
			fillBoard(x, y, d, cnt);
			fillBoard(x, y, (d+1)%4, cnt);
			dfs(here+1, cnt+1);
			eraseBoard(x, y, (d+1)%4, cnt);
			eraseBoard(x, y, d, cnt);
		}
	}
	if (board[x][y] == 4) {
		for (int d=0; d<4; d++) {
			fillBoard(x, y, d, cnt);
			fillBoard(x, y, (d+1)%4, cnt);
			fillBoard(x, y, (d+2)%4, cnt);
			dfs(here+1, cnt+1);
			eraseBoard(x, y, (d+2)%4, cnt);
			eraseBoard(x, y, (d+1)%4, cnt);
			eraseBoard(x, y, d, cnt);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);

	int total = N*M;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			scanf("%d", &board[i][j]);

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (board[i][j] == 6) total--;
			else if (board[i][j] == 5) fillBoardAll(i, j);
			else if (1 <= board[i][j]) cctv.push_back(P(i, j));
		}
	}
	K = cctv.size();

	dfs(0, 2);
	printf("%d\n", total - ret);
	return 0;
}