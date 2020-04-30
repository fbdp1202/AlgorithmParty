// baekjoon 11057 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;
const int DIV_NUM=10007;

int N, dp[MAX_N][10];

int dfs(int here, int num) {
	if (here == N) return 1;
	int &ret = dp[here][num];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=num; i<10; i++)
		ret += dfs(here+1, i);
	ret %= DIV_NUM;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%d\n", dfs(0,0));
	return 0;
}