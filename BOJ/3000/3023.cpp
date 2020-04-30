// baekjoon 3023 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int R, C, x, y;
char board[101][101];

int main() {
	scanf("%d%d", &R, &C);
	for (int i=0; i<R; i++)
		scanf(" %s", board[i]);

	for (int j=0; j<R; j++)
		for (int i=C; i<2*C; i++)
			board[j][i] = board[j][2*C-i-1];

	for (int i=0; i<C*2; i++)
		for (int j=R; j<2*R; j++)
			board[j][i] = board[2*R-j-1][i];

	scanf(" %d %d", &x, &y); x--; y--;
	if (board[x][y] == '.') board[x][y]='#';
	else board[x][y]='.';

	for (int i=0; i<2*R; i++)
		printf("%s\n", board[i]);

	return 0;
}