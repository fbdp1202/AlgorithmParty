// baekjoon 11049 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 555
#define INF 987654321

int N, matrix[MAX_N][2];
int dp[MAX_N][MAX_N];

int main()
{
	scanf("%d", &N);
	for ( int i = 1; i <= N; i++ )
		scanf("%d %d", &matrix[i][0], &matrix[i][1]);

	for ( int i = N; i > 0; i-- )
	{
		for ( int j = i + 1; j <= N; j++ )
		{
			dp[i][j] = INF;
			for ( int k = i; k <= j; k++ )
			{
				int matop = matrix[i][0]*matrix[k][1]*matrix[j][1];
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+matop);
			}
		}
	}
	printf("%d", dp[1][N]);
}