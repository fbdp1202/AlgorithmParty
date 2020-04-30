// baekjoon 1100 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=8;

int ret;
char board[N][N+1];

int main()
{
	for (int i=0; i<N; i++) {
		scanf("%s", board[i]);
		for (int j=0; j<N; j++) {
			if ((i + j) & 1) continue;
			if (board[i][j] == '.') continue;
			ret++;
		}
	}
	printf("%d\n", ret);
	return 0;
}