// baekjoon 2567 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;
const int dir[4][2] = {{0,1}, {1,0},{0,-1},{-1,0}};

int N;
bool board[MAX_N][MAX_N], visited[MAX_N][MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i=y; i<y+10; i++)
			for (int j=x; j<x+10; j++)
				board[i][j] = true;
	}

	int ret = 0;
	for (int i=0; i<101; i++) {
		for (int j=0; j<101; j++) {
			if (board[i][j]) {
				for (int d=0; d<4; d++) {
					int ny = i + dir[d][0];
					int nx = j + dir[d][1];
					if (nx < 0 || nx > 100 || ny < 0 || ny > 100) {
						ret++;
						continue;
					}
					if (!board[ny][nx]) ret++;
				}
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}