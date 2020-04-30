// baekjoon 12100 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 20
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int N, board[MAX_N][MAX_N], result, tmpboard[6][MAX_N][MAX_N];

void PrintBoard(int c) {
	printf("PrintBoard(%d)\n", c);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%d ", tmpboard[c][i][j]);
		}
		puts("");
	}
	puts("");
}

int findMaxBoard() {
	int tmp = 0;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			tmp = max(tmp, tmpboard[5][i][j]);

	return tmp;
}

void lineSum(int c, int x, int y, int d) {
	int px=0, py=0, pv=0;
	for (int i=0; i<N; i++) {
		int curr_x = x + i*dx[d];
		int curr_y = y + i*dy[d];
		if (tmpboard[c][curr_x][curr_y]) {
			if (pv == tmpboard[c][curr_x][curr_y]) {
				tmpboard[c][curr_x][curr_y]*=2;
				tmpboard[c][px][py]=0;
				pv = 0;
			} else {
				pv = tmpboard[c][curr_x][curr_y];
			}
			px=curr_x, py=curr_y;
		}
	}
}

void lineMove(int c, int x, int y, int d) {
	int px=-1, py=-1;
	d = (d + 2)%4;
	for (int i=0; i<N; i++) {
		int curr_x = (x + i*dx[d] + N)%N;
		int curr_y = (y + i*dy[d] + N)%N;
		if (!tmpboard[c][curr_x][curr_y]) {
			if (px==-1 && py==-1)
				px=curr_x; py=curr_y;
		}
		else {
			if (px != -1 && py != -1){
				tmpboard[c][px][py] = tmpboard[c][curr_x][curr_y];
				tmpboard[c][curr_x][curr_y] = 0;
				px = -1, py = -1;
			}
		}
	}
}

void copyBoard(int c) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			tmpboard[c+1][i][j] = tmpboard[c][i][j];
		}
	}
}

void moveBoard(int c) {
	printf("moveBoard[%d]\n", c);
	if (c==5) {
		result = max(result, findMaxBoard());
		return;
	}

	for (int d=0; d<4; d++) {
		copyBoard(c);
		PrintBoard(c);
		for (int i=0; i<N; i++) {
			puts("lineSum");
			int x = (dx[d] == 0) ? i : (dx[d] < 0) ? N-1 : 0;
			int y = (dy[d] == 0) ? i : (dy[d] < 0) ? N-1 : 0;
			lineSum(c+1, x, y, d);
			PrintBoard(c+1);
			puts("lineMove");
			lineMove(c+1, (x==0) ? N-1 : 0, (y==0) ? N-1 : 0, d);
			PrintBoard(c+1);
			moveBoard(c+1);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++){
			scanf("%d", &board[i][j]);
			tmpboard[0][i][j] = board[i][j];
		}
	}

	moveBoard(0);
	printf("%d\n", result);
	return 0;
}