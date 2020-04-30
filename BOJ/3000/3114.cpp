// baekjoon 3114 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N=1502;

char c;
int x, R, C, banana[MAX_N][MAX_N], apple[MAX_N][MAX_N];

int dp[MAX_N][MAX_N];

int dfs(int x, int y)
{
	if (x == R && y == C) return 0;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	// go left
	if (y != C) ret = max(ret, dfs(x, y+1) + banana[x-1][y+1] + apple[R][y] - apple[x][y]);
	if (x != R) ret = max(ret, dfs(x+1, y));
	if (x != R && y != C) ret = max(ret, dfs(x+1, y+1) + banana[x][y+1] + apple[R][y] - apple[x][y]);
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &R, &C);
	for (int i=1; i<=R; i++)
	{
		for (int j=1; j<=C; j++)
		{
			scanf(" %c", &c);
			scanf("%d", &x);
			if (c == 'A') // apple
			{
				apple[i][j] = apple[i-1][j] + x;
				banana[i][j] = banana[i-1][j];
			}
			else // banana
			{
				apple[i][j] = apple[i-1][j];
				banana[i][j] = banana[i-1][j] + x;
			}
		}
	}

	printf("%d\n", dfs(1,1));
	return 0;
}