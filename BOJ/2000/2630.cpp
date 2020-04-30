// baekjoon 2630 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=128;

int N, ans[2];
bool board[MAX_N][MAX_N];

bool check(int x, int y, int s) {
	for (int i=x; i<x+s; i++)
		for (int j=y; j<y+s; j++)
			if (board[i][j] != board[x][y]) return false;

	return true;
}

void dfs(int x, int y, int s) {
	if (check(x, y, s)) {
		ans[board[x][y]]++;
		return;
	}
	dfs(x, y, s/2);
	dfs(x, y+s/2, s/2);
	dfs(x+s/2, y, s/2);
	dfs(x+s/2, y+s/2, s/2);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	dfs(0,0,N);
	printf("%d\n%d\n",ans[0],ans[1]);
	return 0;
}