// baekjoon 1890 yechan
#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX_N 101

int N;
int matrix[MAX_N][MAX_N];
long long dp[MAX_N+10][MAX_N+10];

// int findroot(int x, int y)
// {
// 	if( x == N-1 && y == N-1) return 1;
// 	if( dp[y][x] != -1) return dp[y][x];
// 	int tmp = 0;
// 	int dist = matrix[y][x];
// 	if(dist && dist + x < N)
// 		tmp += findroot(dist+x, y);
// 	if(dist && dist + y < N)
// 		tmp += findroot(x, dist+y);
// 	dp[y][x] = tmp;
// 	return tmp;
// }
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &matrix[i][j]);
	// for(int i=0; i<N; i++)
	// 	for(int j=0; j<N; j++)
	// 		dp[i][j] = -1;
	dp[0][0] = 1;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			int dist = matrix[i][j];
			if(dist != 0){
				dp[i+dist][j] += dp[i][j];
				dp[i][j+dist] += dp[i][j];
			}
		}
	}
	int result = dp[N-1][N-1];
	// int result = findroot(0, 0);
	printf("%lld\n", result);
	return 0;
}