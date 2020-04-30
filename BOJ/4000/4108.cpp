// baekjoon 4108 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=101;
const int dir[8][2] = { {-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1} };
int N, M;
char board[MAX_N][MAX_N];

int main() {
	while (1) {
		scanf("%d%d", &N, &M);
		if (N==0 && M==0) break;

		for (int i=0; i<N; i++)
			scanf("%s", board[i]);


		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (board[i][j] == '*') {
					printf("*");
				} else {
					int num = 0;
					for (int d=0; d<8; d++) {
						int nx = i + dir[d][0];
						int ny = j + dir[d][1];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (board[nx][ny] == '*') {
							num++;
						}
					}
					printf("%d", num);
				}
			}
			puts("");
		}

	}
	return 0;
}