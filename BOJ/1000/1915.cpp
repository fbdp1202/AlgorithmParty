// baekjoon 1915 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1001
int n, m, dp[MAX_N][MAX_N];
char matrix[MAX_N][MAX_N];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf(" %c", &matrix[i][j]);

	int max_len = 0;
	int tmp = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			tmp = 0;
			if(matrix[i][j]=='1'){
				tmp = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1;
			}
			max_len = max(max_len, tmp);
			dp[i][j] = tmp;
		}
	}
	printf("%d", max_len * max_len);
}