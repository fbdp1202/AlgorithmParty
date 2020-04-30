// baekjoon 1780 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2187;

int N, board[MAX_N][MAX_N];
int ans[3];

bool check(int x, int y, int size) {
	for (int i=x; i<x+size; i++)
		for (int j=y; j<y+size; j++)
			if (board[x][y] != board[i][j])
				return false;

	return true;
}

void dfs(int x, int y, int size) {
	if (check(x, y, size)) {
		ans[board[x][y]+1]++;
		return;
	}
	size /= 3;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			dfs(x+i*size, y+j*size, size);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);
	dfs(0, 0, N);
	for (int i=0; i<3; i++) printf("%d\n", ans[i]);
	return 0;
}