// baekjoon 11070 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, M;
int board[1111][2];

int f(int a, int b) {
	if (a == 0) return 0;
	return (1LL*a*a*1000)/(1LL*a*a+1LL*b*b);
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(board, 0, sizeof(board));
		scanf("%d%d", &N, &M);
		int a, b, p, q;
		for (int i=0; i<M; i++) {
			scanf("%d%d%d%d", &a, &b, &p, &q);
			board[a][0] += p;
			board[a][1] += q;
			board[b][1] += p;
			board[b][0] += q;
		}

		int maxV = f(board[1][0], board[1][1]);
		int minV = f(board[1][0], board[1][1]);
		for (int i=2; i<=N; i++) {
			int value = f(board[i][0], board[i][1]);
			maxV = max(maxV, value);
			minV = min(minV, value);
		}
		printf("%d\n", maxV);
		printf("%d\n", minV);
	}
	return 0;
}