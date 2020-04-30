// baekjoon 1102 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF_MAX 987654321
int N, S, P, W[16][16], dp[1<<16];

int findCost(int state, int cnt) {
	if (~dp[state]) return dp[state];
	if (cnt >= P) return 0;

	int ret = INF_MAX;
	for (int i=0; i<N; i++) {
		if (!(state>>i & 1)) {
			int nx = state | 1<<i;
			int minValue = INF_MAX;
			for (int j=0; j<N; j++){
				if (state >> j & 1){
					if (minValue > W[j][i]) {
						minValue = W[j][i];
					}
				}
			}
			ret = min(ret, findCost(nx, cnt + 1) + minValue);
		}
	}
	dp[state] = ret;
	return ret;
}

int main() {
	char data[16];
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &W[i][j]);

	scanf("%s", data);
	int cnt = 0;
	for (int i=0; i<N; i++) {
		if(data[i] == 'Y') {
			S |= (1<<i);
			cnt++;
		}
	}
	scanf("%d", &P);
	memset(dp, -1, sizeof(dp));

	int result = INF_MAX;
	result = min(result, findCost(S, cnt));

	if (result == INF_MAX) puts("-1");
	else printf("%d\n", result);

	return 0;
}