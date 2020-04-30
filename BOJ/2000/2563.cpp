// baekjoon 2563 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define PAPER_W 10
int N, sx, sy;
int bsize;
bool board[MAX_N][MAX_N];

void draw(int x, int y)
{
	for(int i=y; i<y+PAPER_W; i++) 
		for(int j=x; j<x+PAPER_W; j++)
			if(!board[i][j]) 
				bsize++, board[i][j] = true;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &sx, &sy), draw(sx, sy);
	printf("%d", bsize);
}