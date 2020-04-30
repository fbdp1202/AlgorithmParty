// baekjoon 1563 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int DIV_NUM=1000000;
const int MAX_N=1001;
int N, dp[MAX_N][3][4];

int go(int num, int late, int absent) {
	if (!late || !absent) return 0;
	if (num == 0) return 1;
	int &ret=dp[num][late][absent];
	if (ret!=-1) return ret;
	ret=go(num-1, late, 3)+go(num-1, late-1, 3)+go(num-1, late, absent-1);
	ret%=DIV_NUM;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%d", go(N,2,3));
	return 0;
}