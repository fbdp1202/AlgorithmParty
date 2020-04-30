// baekjoon 14731 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 501
int N, x1, y1, x2, y2, result;
bool board[MAX_N][MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int x=x1; x<x2; x++)
			for (int y=y1; y<y2; y++)
				board[x][y]=true;
	}
	for (int x=0; x<MAX_N; x++)
		for (int y=0; y<MAX_N; y++)
			if (board[x][y])
				result++;

	printf("%d", result);
	return 0;
} 