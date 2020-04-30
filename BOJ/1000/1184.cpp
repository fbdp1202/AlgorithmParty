// baekjoon 1184 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;

int N;
int board[MAX_N][MAX_N];

inline int getRect(int sx, int sy, int ex, int ey) {
	return (board[ex][ey] - board[sx-1][ey] - board[ex][sy-1] + board[sx-1][sy-1]);
}

bool check(int asx, int asy, int aex, int aey, int bsx, int bsy, int bex, int bey) {
	return getRect(asx, asy, aex, aey) == getRect(bsx, bsy, bex, bey);
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			int x; scanf("%d", &x);
			board[i][j] = x + board[i-1][j] + board[i][j-1] - board[i-1][j-1];
		}
	}

	int ret = 0;
	for (int aex=1; aex<N; aex++)
		for (int aey=1; aey<N; aey++)
			for (int asx=1; asx<=aex; asx++)
				for (int asy=1; asy<=aey; asy++)
					for (int bex=aex+1; bex<=N; bex++)
						for (int bey=aey+1; bey<=N; bey++) {
							if (check(asx, asy, aex, aey, aex+1, aey+1, bex, bey)) ret++;
							if (check(aex+1, asy, bex, aey, asx, aey+1, aex, bey)) ret++;
						}
	printf("%d\n", ret);
	return 0;
}