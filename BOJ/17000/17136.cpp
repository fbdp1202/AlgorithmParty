// baekjoon 17136 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_INF=1e9;

int board[10][10], ans[6], remain;
bool visited[10][10][6];

void fill(int sx, int sy, int size) {
	for (int x=sx; x<sx+size; x++)
		for (int y=sy; y<sy+size; y++)
			board[x][y] = 1;
	remain += size*size;
}

bool erase(int sx, int sy, int size) {
	for (int x=sx; x<sx+size; x++)
		for (int y=sy; y<sy+size; y++)
			if (board[x][y] == 0)
				return false;

	for (int x=sx; x<sx+size; x++)
		for (int y=sy; y<sy+size; y++)
			board[x][y] = 0;

	remain -= size*size;
	return true;
}

int dfs() {
	if (remain == 0) return 0;

	int ret = MAX_INF;
	for (int s=5; s>=1; s--) {
		if (!ans[s]) continue;
		ans[s]--;
		for (int i=0; i<=10-s; i++) {
			for (int j=0; j<=10-s; j++) {
				if (visited[i][j][s]) continue;
				visited[i][j][s] = true;
				if (erase(i,j,s)) {
					int r = dfs();
					fill(i,j,s);
					if (r == -1) continue;
					ret = min(ret, r+1);
				}
				visited[i][j][s] = false;
			}
		}
		ans[s]++;
	}
	return (ret == MAX_INF) ? -1 : ret;
}

int main() {
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++) {
			scanf("%d", &board[i][j]);
			remain += board[i][j];
		}

	for (int i=1; i<6; i++)
		ans[i]=5;

	printf("%d\n", dfs());
	return 0;
}