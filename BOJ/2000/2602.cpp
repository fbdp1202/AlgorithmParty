// baekjoon 2602 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_L=101;
const int MAX_S=21;

int N, K;
char str[MAX_S];
char stair[2][MAX_L];
int dp[MAX_S][MAX_L][2];
// (밟아야하는 계단)(최소 시작 지점)(위 or 아래)

int dfs(int here, int start, int up) {
	if (here == K) return 1;

	int &ret = dp[here][start][up];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=start; i<N; i++)
		if (str[here] == stair[up][i])
			ret += dfs(here+1, i+1, up ^ 1);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s", str);
	for (int i=0; i<2; i++) 
		scanf("%s", stair[i]);

	N = strlen(stair[0]);
	K = strlen(str);

	printf("%d\n", dfs(0, 0, 0) + dfs(0, 0, 1));
	return 0;
}