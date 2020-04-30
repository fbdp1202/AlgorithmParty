// baekjoon 13565 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1001;
const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

int N, M;
char board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int d=0; d<4; d++) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (visited[nx][ny]) continue;
		if (board[nx][ny] == '1') continue;
		dfs(nx, ny);
	}
}


int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	for (int i=0; i<M; i++) {
		if (visited[0][i] || board[0][i] == '1') continue;
		dfs(0, i);
	}

	bool check = false;

	for (int i=0; i<M; i++)
		check |= visited[N-1][i];

	puts(check ? "YES":"NO");
	return 0;
}