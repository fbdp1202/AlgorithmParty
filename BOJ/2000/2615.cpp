// baekjoon 2615 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=21;
const int dir[4][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}};

int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][4];

int dfs(int x, int y, int d, int count) {
	visited[x][y][d]=true;
	int nx = x + dir[d][0], ny = y + dir[d][1];
	if (board[x][y] == board[nx][ny]) {
		return dfs(nx, ny, d, count+1);
	}
	return count;
}

int main() {
	for (int i=1; i<MAX_N-1; i++)
		for (int j=1; j<MAX_N-1; j++)
			scanf("%d", &board[i][j]);

	for (int i=1; i<MAX_N-1; i++) {
		for (int j=1; j<MAX_N-1; j++) {
			if (!board[i][j]) continue;
			for (int d=0; d<4; d++) {
				if (visited[i][j][d]) continue;
				if (dfs(i, j, d, 1) == 5) {
					if (d == 3) i+=4, j-=4;
					return !printf("%d\n%d %d\n", board[i][j], i, j);
				}
			}
		}
	}
	printf("0\n");
	return 0;
}