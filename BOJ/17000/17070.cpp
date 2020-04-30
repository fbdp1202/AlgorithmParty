// baekjoon 17070 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=17;

int N;
int board[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][3];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	dp[0][1][0]=1;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (board[i][j]) continue;
			for (int k=0; k<3; k++) {
				if (!board[i][j+1] && k != 1) dp[i][j+1][0] += dp[i][j][k];
				if (!board[i+1][j] && k != 0) dp[i+1][j][1] += dp[i][j][k];
				if (board[i+1][j] + board[i][j+1] + board[i+1][j+1] == 0) dp[i+1][j+1][2] += dp[i][j][k];
			}
		}
	}
	printf("%d\n", dp[N-1][N-1][0]+dp[N-1][N-1][1]+dp[N-1][N-1][2]);
	return 0;
}