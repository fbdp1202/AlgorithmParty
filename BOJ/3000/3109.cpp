// baekjoon 3109 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=10001;
const int MAX_M=501;
const int dir[3] = {-1, 0, 1};

int N, M, ret;
char board[MAX_N][MAX_M];

bool dfs(int x, int y) {
	if (y == M-1) return true;

	bool ret = false;
	for (int d=0; d<3; d++) {
		int nx = x + dir[d];
		int ny = y + 1;
		if (nx < 0 || nx >= N) continue;
		if (board[nx][ny] == 'x') continue;
		board[nx][ny] = 'x';
		ret = dfs(nx, ny);
		if (ret) return true;
		board[nx][ny] = '.';
	}
	for (int d=0; d<3; d++) {
		int nx = x + dir[d];
		int ny = y + 1;
		if (nx < 0 || nx >= N) continue;
		board[nx][ny] = 'x';
	}
	return false;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	for (int i=0; i<N; i++)
		if (dfs(i, 0))
			ret++;
	printf("%d\n", ret);
	return 0;
}