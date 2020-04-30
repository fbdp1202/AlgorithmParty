// baekjoon 9455 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 101;

int T, N, M, board[MAX_N][MAX_N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		for (int i=N-1; i>=0; i--)
			for (int j=0; j<M; j++)
				scanf("%d", &board[i][j]);

		int ret = 0;
		for (int j=0; j<M; j++) {
			int cnt = 0;
			for (int i=0; i<N; i++) {
				if (board[i][j]) {
					ret += i - cnt;
					cnt++;
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}