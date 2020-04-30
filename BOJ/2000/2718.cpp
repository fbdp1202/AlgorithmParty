// baekjoon 2718 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, dp[25];

int getDP(int x) {
	int &ret=dp[x];
	if (ret) return ret;
	ret+=getDP(x-2)+getDP(x-1);
	for (int i=x-2; i>=0; i-=2)
		ret+=getDP(i)*3;
	for (int i=x-3; i>=0; i-=2)
		ret+=getDP(i)*2;
	return ret;
}

int main() {
	scanf("%d", &T);
	dp[0]=dp[1]=1;
	getDP(24);
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
	return 0;
}