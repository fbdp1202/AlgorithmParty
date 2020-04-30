// baekjoon 14890 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=101;

int N, L;
int board[MAX_N][MAX_N][2];
bool visited[MAX_N][MAX_N][2];

int getlen(int i, int x, int m, int dir, int match) {
	if (visited[i][x][m]) return 0;
	if (x < 0 || x >= N) return 0;
	if (board[i][x][m] != match) return 0;
	return 1 + getlen(i, x+dir, m, dir, match);
}

int check(int i, int m) {
	for (int j=1; j<N; j++) {
		if (board[i][j-1][m] == board[i][j][m]) continue;
		if (abs(board[i][j-1][m] - board[i][j][m]) != 1) return 0;
		if (board[i][j-1][m] < board[i][j][m]) {
			if (L > getlen(i,j-1,m,-1,board[i][j-1][m])) return 0;
			continue;
		}
		if (board[i][j-1][m] > board[i][j][m]) {
			if (L > getlen(i,j,m,1,board[i][j][m])) return 0;
			j += L-1;
			visited[i][j][m]=true;
			continue;
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int x; scanf("%d", &x);
			board[i][j][0]=x;
			board[j][i][1]=x;
		}
	}

	int ret = 0;
	for (int i=0; i<N; i++)
		ret += check(i,0)+check(i,1);
	printf("%d\n", ret);
	return 0;
}