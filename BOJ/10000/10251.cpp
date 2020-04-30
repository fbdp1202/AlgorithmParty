// baekjoon 10251 yechan
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int MAX_N=101;
const int MAX_INF=2e9;

int T, N, M, L, G;
int board[MAX_N][MAX_N][2]; // (right, down)
int dp[MAX_N][MAX_N][MAX_N*2][2];


int main()
{
	scanf("%d", &T);
	while (T--) {
		memset(board, 0, sizeof(board));
		for (int i=0; i<MAX_N; i++)
			for (int j=0; j<MAX_N; j++)
				for (int d=0; d<MAX_N*2; d++)
					for (int k=0; k<2; k++)
						dp[i][j][d][k] = MAX_INF;

		scanf("%d%d%d%d", &N, &M, &L, &G);

		for (int i=0; i<N; i++)
			for (int j=0; j<M-1; j++)
				scanf("%d", &board[i][j][0]);

		for (int i=0; i<N-1; i++)
			for (int j=0; j<M; j++)
				scanf("%d", &board[i][j][1]);

		dp[0][0][0][0] = dp[0][0][0][1] = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (j < M - 1) {
					for (int d=0; d<N+M; d++) {
						if (dp[i][j][d][0] == MAX_INF) continue;
						dp[i][j+1][d][0] = min(dp[i][j+1][d][0], dp[i][j][d][0] + board[i][j][0]);
					}
					for (int d=0; d<N+M; d++) {
						if (dp[i][j][d][1] == MAX_INF) continue;
						dp[i][j+1][d+1][0] = min(dp[i][j+1][d+1][0], dp[i][j][d][1] + board[i][j][0]);
					}
				}
				if (i < N - 1) {
					for (int d=0; d<N+M; d++) {
						if (dp[i][j][d][0] == MAX_INF) continue;
						dp[i+1][j][d+1][1] = min(dp[i+1][j][d+1][1], dp[i][j][d][0] + board[i][j][1]);
					}
					for (int d=0; d<N+M; d++) {
						if (dp[i][j][d][1] == MAX_INF) continue;
						dp[i+1][j][d][1] = min(dp[i+1][j][d][1], dp[i][j][d][1] + board[i][j][1]);
					}
				}
			}
		}
		int ret = MAX_INF;
		for (int i=0; i<N+M; i++) {
			if (min(dp[N-1][M-1][i][0], dp[N-1][M-1][i][1]) <= G) {
				ret = i;
				break;
			}
		}
		printf("%d\n", ret == MAX_INF ? -1 : ret + (N-1+M-1)*L);
	}
	return 0;
}