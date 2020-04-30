// baekjoon 2291 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=11;
const int MAX_M=221;

typedef long long ll;

int N, M, K;
ll dp[MAX_N][MAX_M][MAX_M]; // dp[남은 자리수][전 값][남은 값]
int ans[MAX_N];

int dfs(int pos, int pv, int remain) {
	if (pos == 0) return 0;
	if (pv > remain) return 0;
	int &ret = dp[pos][pv][remain];
	if (ret != -1) return ret;

	ret = 0;
	for (int i=1; i<=remain/pos; i++) {
		ret += dfs(pos-1, i, remain-i);
	}
	return ret;
}

void findSequence() {

}

int main() {
	for (int i=0; i<MAX_N; i++)
		for (int j=0; j<MAX_M; j++)
			for (int k=0; k<MAX_M; k++)
				dp[i][j][k] = -1;

	scanf("%d%d%d", &N, &M, &K);
	findSequence();
	for (int i=N; i>=1; i--)
		printf("%d ", ans[i]);
	
	puts("");
	return 0;
}