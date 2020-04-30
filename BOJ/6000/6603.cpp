// baekjoon 6603 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 50
#define MAX_R 6
int T, N, bnum[MAX_N], result[MAX_R];

void BFS(int s, int p)
{
	if ( p == MAX_R-1 ) {
		result[p] = bnum[s];
		for ( int i=0; i<MAX_R; i++ )
			printf("%d ", result[i]);
		printf("\n");
		return;
	}
	result[p] = bnum[s];
	for ( int i=s+1; i<N; i++ ) {
		if ( N-i >= MAX_R-(p+1) ) {
			BFS(i, p+1);
		}
	}
}

int main()
{
	do {
		scanf("%d", &N);
		for ( int i=0; i<N; i++ )
			scanf("%d", &bnum[i]);
		for ( int i=0; i<N; i++ )
			BFS(i, 0);
		printf("\n");
	} while(N);

	return 0;
}