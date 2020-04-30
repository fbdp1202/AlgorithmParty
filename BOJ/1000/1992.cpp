// baekjoon 1992 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=65;

int N;
char board[MAX_N][MAX_N];

bool check(int x, int y, int size) {
	for (int i=x; i<x+size; i++)
		for (int j=y; j<y+size; j++)
			if (board[x][y] != board[i][j])
				return false;
	return true;
}

void solve(int x, int y, int size) {
	if (check(x, y, size)) {
		printf("%c", board[x][y]);
		return;
	}
	size/=2;
	printf("(");
	solve(x, y, size);
	solve(x, y+size, size);
	solve(x+size, y, size);
	solve(x+size, y+size, size);
	printf(")");
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);
	solve(0,0,N);
	return 0;
}