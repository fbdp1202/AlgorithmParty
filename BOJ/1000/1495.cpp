// baekjoon 1495 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 101
#define MAX_M 1000

int N, S, M, volume[MAX_N];
int dp[MAX_N][MAX_M];

int control_Volume(int i, int P)
{
	if(i == N) return P;
	if(dp[i][P] != -2) return dp[i][P];
	int tmp = -1;
	if(P - volume[i]>=0) tmp = max(tmp, control_Volume(i+1, P - volume[i]));
	if(P + volume[i]<=M) tmp = max(tmp, control_Volume(i+1, P + volume[i]));
	dp[i][P] = tmp;
	return tmp;
}

int main()
{
	scanf("%d %d %d", &N, &S, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &volume[i]);
	for(int i=0; i<MAX_N; i++){
		for(int j=0; j<MAX_M; j++){
			dp[i][j] = -2;
		}
	}

	int result = control_Volume(0, S);
	printf("%d", result);
}
