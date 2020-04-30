// baekjoon 2447 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2187;

int N;
char board[MAX_N][MAX_N+1];

void solve(int x, int y, int size, int flag) {
	if (size == 1) {
		board[x][y]=flag ? '*':' ';
		return;
	}
	size/=3;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			solve(x+size*i, y+size*j, size, flag && (i!=1 || j!=1));
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			board[i][j] = ' ';
	solve(0,0,N,true);
	for (int i=0; i<N; i++)
		printf("%s\n", board[i]);
	return 0;
}