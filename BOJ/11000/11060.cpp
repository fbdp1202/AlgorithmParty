// baekjoon 11060 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1101
#define INF 987654321
int N, miro[MAX_N], dp[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &miro[i]);

	fill(dp, dp+MAX_N, INF);
	dp[0] = 0;

	for(int i=0; i<N; i++){
		int dist = miro[i];
		if(dp[i] !=INF)
			for(int j=i+1; j<i+dist+1; j++)
				dp[j] = min(dp[i]+1, dp[j]);
	}
	if(dp[N-1] == INF) dp[N-1] = -1;
	printf("%d", dp[N-1]);
}