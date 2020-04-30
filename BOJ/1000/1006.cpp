// baekjoon 1006 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=10001;

int T, N, W, x, board[2][MAX_N];
int dp[4][2][MAX_N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &W);
		for (int i=0; i<2; i++) {
			for (int j=0; j<N; j++) {
				scanf("%d", &x);
				board[i][j]=(x+W-1)/W;
			}
		}
		if (N == 1) {
			printf("%d\n", max(board[0][0], board[1][0]));
			continue;
		}
		dfs()
	}
	return 0;
}