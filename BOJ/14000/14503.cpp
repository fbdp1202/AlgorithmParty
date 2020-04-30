// baekjoon 14503 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int dir[4][2]={{0,-1}, {-1,0}, {0,1}, {1,0}};

int N, M;
int x, y, d;
int board[51][51];

int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &x, &y, &d);
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			scanf("%d", &board[i][j]);

	int ret = 0;
	while (1) {
		if (!board[x][y]) ret++;
		board[x][y] = 2;
		bool done = false;
		for (int i=0; i<5; i++) {
			if (i == 4) { // 모두 청소 되어 있을때,
				int nx = x + dir[(d+3)%4][0]; // 후진
				int ny = y + dir[(d+3)%4][1];
				if (board[nx][ny] != 1) x = nx, y = ny;
				else done = true;
				break;
			}
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			d = (d+3)%4;
			if (!board[nx][ny]) {
				x = nx;
				y = ny;
				break;
			}
		}
		if (done) break;
	}
	printf("%d\n", ret);
	return 0;
}