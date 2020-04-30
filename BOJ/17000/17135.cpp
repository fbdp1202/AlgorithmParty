// baekjoon 17135 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
const int MAX_N=16;

int N, M, D;
int board[MAX_N][MAX_N];
int tBoard[MAX_N][MAX_N];

void move() {
	for (int i=1; i<N; i++) {
		for (int j=0; j<M; j++) {
			tBoard[i-1][j] = tBoard[i][j];
			tBoard[i][j] = 0;
		}
	}
}

int getDist(int p, int x, int y) {
	return (x+1)+abs(p-y);
}

P killOne(int p) {
	int minDist = 1e9;
	P ret = P(-1,-1);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (!tBoard[i][j]) continue;
			int tmp = getDist(p, i, j);
			if (tmp > D) continue;
			if (tmp < minDist) {
				minDist = tmp;
				ret = P(i, j);
			} else if (tmp == minDist) {
				if (j < ret.second) {
					ret = P(i, j);
				}
			}
		}
	}
	return ret;
}

int remove(P a) {
	int x = a.first, y = a.second;
	if (x == -1 || y == -1) return 0;
	if (tBoard[x][y] == 0) return 0;
	tBoard[x][y] = 0;
	return 1;
}

int killThree(int a, int b, int c) {
	P aa = killOne(a);
	P bb = killOne(b);
	P cc = killOne(c);

	int ret = 0;
	ret += remove(aa);
	ret += remove(bb);
	ret += remove(cc);
	return ret;
}

int dfs(int a, int b, int c, int num) {
	if (num == 0) return 0;
	int ret = killThree(a, b, c);
	move();
	ret += dfs(a, b, c, num-1);
	return ret;
}

void copy_board() {
	for (int i=0; i<N; i++) for (int j=0; j<M; j++)
		tBoard[i][j] = board[i][j];
}

int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i=N-1; i>=0; i--)
		for (int j=0; j<M; j++)
			scanf("%d", &board[i][j]);

	int ret = 0;
	for (int a=0; a<M; a++)
		for (int b=a+1; b<M; b++)
			for (int c=b+1; c<M; c++) {
				copy_board();
				ret = max(ret, dfs(a, b, c, N));
			}
	printf("%d\n", ret);
	return 0;
}