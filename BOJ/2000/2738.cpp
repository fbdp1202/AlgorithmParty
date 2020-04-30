// baekjoon 2738 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, M, board[MAX_N][MAX_N], x;

int main() {
	scanf("%d%d", &N, &M);
	for (int k=0; k<2; k++) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				scanf("%d", &x);
				board[i][j] += x;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			printf("%d ", board[i][j]);
		puts("");
	}
	return 0;
}