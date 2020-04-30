// baekjoon 1937 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 502
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int n, food[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int dfs(int x, int y)
{
	if(~dp[x][y]) return dp[x][y];
	int tmp = 1;
	for(int d=0; d<4; d++){
		int nx = x + dx[d], ny = y + dy[d];
		if(food[nx][ny]>food[x][y]) tmp = max(tmp, dfs(nx, ny)+1);
	}
	dp[x][y] = tmp;
	return tmp;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", &food[i][j]), dp[i][j] = -1;

	int max_len = 1;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			max_len = max(max_len,dfs(i, j));
		}
	}
	printf("%d", max_len);
	return 0;
}