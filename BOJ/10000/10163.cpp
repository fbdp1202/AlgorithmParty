// baekjoon 10163 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;
int N, board[MAX_N][MAX_N], x, y, W, H;

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d%d%d%d", &x, &y, &W, &H);
		for (int j=y; j<y+H; j++)
			for (int k=x; k<x+W; k++)
				board[j][k]=i;
	}
	for (int i=1; i<=N; i++) {
		int ret = 0;
		for (int j=0; j<MAX_N; j++)
			for (int k=0; k<MAX_N; k++)
				if (board[j][k] == i)
					ret++;
		printf("%d\n", ret);
	}

	return 0;
}