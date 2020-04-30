// baekjoon 11586 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int N, K;
char board[MAX_N][MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);
	scanf("%d", &K);
	if (K == 1) {
		for (int i=0; i<N; i++)
			printf("%s\n", board[i]);
	}
	if (K == 2) {
		for (int i=0; i<N; i++) {
			for (int j=N-1; j>=0; j--)
				printf("%c", board[i][j]);
			puts("");
		}
	}
	if (K == 3) {
		for (int i=N-1; i>=0; i--)
			printf("%s\n", board[i]);
	}
	return 0;
}