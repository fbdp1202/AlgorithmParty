// baekjoon 7579 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, c, dp[10001];
int memory[101], cost[101];

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%d", &memory[i]);
	for (int i=0; i<N; i++) {
		scanf("%d", &cost[i]);
	}

	for (int i=0; i<N; i++) {
		for (int j=10000-cost[i]; j>=1; j--) {
			if (dp[j]) {
				dp[j+cost[i]] = max(dp[j+cost[i]], dp[j]+memory[i]);
			}
		}
		dp[cost[i]] = max(dp[cost[i]], memory[i]);
	}

	for (int j=0; j<10001; j++) {
		if (M <= dp[j]) {
			printf("%d\n", j);
			break;
		}
	}

	return 0;
}