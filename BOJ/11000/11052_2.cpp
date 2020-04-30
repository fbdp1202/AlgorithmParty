// baekjoon 11052 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1001;

int N, cost[MAXN], dp[MAXN];

int backtracking(int num) {
	int &ret = dp[num];
	if (~ret) return ret;
	ret = cost[num];
	for (int i=1; i<num; i++)
		ret = max(ret, backtracking(num-i) + backtracking(i));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &cost[i]);
	printf("%d\n",backtracking(N));
	return 0;
}