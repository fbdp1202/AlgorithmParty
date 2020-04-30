// baekjoon 1992 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 64
int N;
char board[MAX_N][MAX_N+1];

bool checkboard(int x, int y, int n) {
	char tmp = board[x][y];
	for (int i=x; i<x+n; i++) {
		for (int j=y; j<y+n; j++) {
			if (tmp != board[i][j]) return false;
		}
	}
	return true;
}

void Qtree(int x, int y, int n) {
	if (checkboard(x, y, n)) {
		printf("%c", board[x][y]);
	} else {
		printf("(");
		n /= 2;
		Qtree(x, y, n);
		Qtree(x, y+n, n);
		Qtree(x+n, y, n);
		Qtree(x+n, y+n, n);
		printf(")");
	}
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", &board[i]);
	Qtree(0, 0, N);
	return 0;
}