// baekjoon 1926 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=502;
const int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int N, M, ans, piece;
bool board[MAX_N][MAX_N];

int dfs(int x, int y)
{
	int ret = 1;
	board[x][y]=0;
	for (int d=0; d<4; d++)
		if (board[x+dir[d][0]][y+dir[d][1]])
			ret += dfs(x+dir[d][0], y+dir[d][1]);
	return ret;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			scanf("%d", &board[i][j]);

	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			if (board[i][j]) ans = max(ans, dfs(i, j)), piece++;
	printf("%d\n%d\n", piece, ans);
	return 0;
}