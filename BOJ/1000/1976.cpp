// baekjoon 1976 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=201;

int N, M;
bool board[MAX_N][MAX_N];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	for (int i=0; i<N; i++)
		board[i][i]=true;

	for (int k=0; k<N; k++)
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++) {
				if (i == j) continue;
				board[i][j] |= board[i][k] && board[k][j];
			}

	int x, y;
	if (M) scanf("%d", &x);
	x--;
	bool check = true;
	for (int i=1; i<M; i++) {
		y = x;
		scanf("%d", &x);
		x--;
		if (!board[x][y]) check = false;
	}
	puts(check ? "YES" : "NO");
	return 0;
}