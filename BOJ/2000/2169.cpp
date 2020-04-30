// baekjoon 2169 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1002

int N, M, miro[MAX_N][MAX_N];
int dpl[MAX_N][MAX_N], dpr[MAX_N][MAX_N];

int main()
{
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &miro[i][j]);

	for(int i=1; i<=M; i++){
		dpl[1][i] = miro[1][i] + dpl[1][i-1];
		dpr[1][i] = dpl[1][i];
	}

	for(int i=2; i<=N; i++){
		dpl[i][1] = miro[i][1] + max(dpl[i-1][1], dpr[i-1][1]);
		dpr[i][M] = miro[i][M] + max(dpl[i-1][M], dpr[i-1][M]);
		for(int j=2; j<=M; j++){
			dpl[i][j] = miro[i][j] + max(dpl[i][j-1], max(dpl[i-1][j], dpr[i-1][j]));
		}
		for(int j=M-1; j>0; j--){
			dpr[i][j] = miro[i][j] + max(dpr[i][j+1], max(dpl[i-1][j], dpr[i-1][j]));
		}
	}
	int result = max(dpr[N][M], dpl[N][M]);
	printf("%d", result);
	return 0;
}