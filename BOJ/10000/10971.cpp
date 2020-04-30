// baekjoon 10971 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 10
#define INF 1e9

int weight[MAX_N][MAX_N], dp[MAX_N][1<<10];
int ans = INF;
int N;

int TripCycle(int curr, int state) {
	if (state == (1<<N)-1) return weight[curr][0];
	if (dp[curr][state] != -1) return dp[curr][state];

	int ret = INF;
	for (int i=0; i<N; i++) {
		if ((state>>i) & 1) continue;
		if (weight[curr][i] == INF) continue;
		int nstate = state | (1<<i);
		ret = min(ret, weight[curr][i]+TripCycle(i, nstate));
	}
	dp[curr][state]=ret;

	return dp[curr][state];
}

int main() {
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<N; i++) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &weight[i][j]);
			if (!weight[i][j]) weight[i][j] = INF;
		}
	}

	printf("%d\n",TripCycle(0,1));
	return 0;
}