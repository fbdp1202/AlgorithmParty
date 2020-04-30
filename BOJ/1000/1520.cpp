// baekjoon 1520 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_LEN 502
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int n, m;
int A[MAX_LEN][MAX_LEN], dp[MAX_LEN][MAX_LEN];

int findroot(int x, int y)
{
	if(x == n && y == m) return 1;
	if(~dp[x][y]) return dp[x][y];
	dp[x][y] = 0;
	for(int i=0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(A[nx][ny] && A[nx][ny] < A[x][y])
			dp[x][y] += findroot(nx, ny);
	}
	return dp[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &A[i][j]), dp[i][j] = -1;

	int result = findroot(1, 1);
	printf("%d\n", result);
	return 0;
}