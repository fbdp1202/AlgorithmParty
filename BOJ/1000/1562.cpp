// baekjoon 1562 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define DIV_NUM 1000000000

int N, ans, dp[101][10][1<<10];

int findDP(int num, int p, int state) {
	if (dp[num][p][state]) 
		return dp[num][p][state];

	if (num == N)
		return (state == (1<<10) - 1) ? 1 : 0;

	int ret = 0;
	if (p + 1 < 10)
		ret += findDP(num+1, p+1, state | 1<<(p+1));
	if (p - 1 >= 0)
		ret += findDP(num+1, p-1, state | 1<<(p-1));

	return dp[num][p][state] = ret % DIV_NUM;
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<10; i++) {
		ans += findDP(1, i, 1<<i);
		ans %= DIV_NUM;
	}
	printf("%d\n", ans);
	return 0;
}