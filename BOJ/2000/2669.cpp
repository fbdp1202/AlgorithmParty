// baekjoon 2699 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=102;

int x1, y1, x2, y2, ret;
bool board[MAX_N][MAX_N];

int main() {
	for (int i=0; i<4; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int i=y1; i<y2; i++)
			for (int j=x1; j<x2; j++)
				board[i][j]=true;
	}
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<MAX_N; j++)
			ret+=board[i][j];
	printf("%d\n", ret);
	return 0;
}