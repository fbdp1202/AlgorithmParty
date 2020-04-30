// baekjoon 10994 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char board[444][444];

void drawLine(int start, int len) {
	for (int i=start; i<=len; i++) {
		board[start][i] = '*';
		board[len][i] = '*';
		board[i][start] = '*';
		board[i][len] = '*';
	}
	if (len == 1) return;

	drawLine(start+2, len-2);
}

int main()
{
	scanf("%d", &N);

	int len = 1+4*(N-1);

	for (int i=1; i<=len; i++)
		for (int j=1; j<=len; j++)
			board[i][j]=' ';

	drawLine(1, len);

	for (int i=1; i<=len; i++) {
		for (int j=1; j<=len; j++)
			printf("%c", board[i][j]);
		puts("");
	}

	return 0;
}