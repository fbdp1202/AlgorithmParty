// baekjoon 3035 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=51;

int R, C, ZR, ZC;
char board[MAX_N][MAX_N];

int main()
{
	scanf("%d%d", &R, &C);
	scanf("%d%d", &ZR, &ZC);

	for (int i=0; i<R; i++)
		scanf("%s", board[i]);

	for (int i=0; i<R; i++) {
		for (int zr=0; zr<ZR; zr++) {
			for (int j=0; j<C; j++) {
				for (int zc=0; zc<ZC; zc++) {
					printf("%c", board[i][j]);
				}
			}
			puts("");
		}
	}

	return 0;
}