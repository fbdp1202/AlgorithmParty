// baekjoon 2216 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=3001;
const int MIN_INF=-1e9;

int A, B, C;
int Xlen, Ylen;
int dp[MAX_N][MAX_N];
char X[MAX_N], Y[MAX_N];

int dfs(int up, int down) {
	if (up == Xlen && down == Ylen) return 0;

	int &ret = dp[up][down];
	if (ret != MIN_INF) return ret;

	if (up != Xlen) ret = max(ret, dfs(up+1, down)+B);
	if (down != Ylen) ret = max(ret, dfs(up, down+1)+B);
	if (up != Xlen && down != Ylen) ret = max(ret, dfs(up+1, down+1)+((X[up]==Y[down]) ? A:C));
	return ret;
}

int main() {
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<MAX_N; j++)
			dp[i][j] = MIN_INF;

	scanf("%d %d %d", &A, &B, &C);
	scanf("%s%s", X, Y);
	Xlen = strlen(X), Ylen = strlen(Y);
	printf("%d\n", dfs(0,0));
	return 0;
}