// baekjoon 2629 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=31;
const int MAX_V=40001;

int N, M, sum;
bool dp[MAX_N][MAX_V];

int main() {
	scanf("%d", &N);

	dp[0][0]=true;
	for (int i=0; i<N; i++) {
		int x; scanf("%d", &x);
		for (int j=sum; j>=0; j--) {
			dp[i+1][j+x] |= dp[i][j];
			dp[i+1][max(j-x,0)] |= dp[i][j];
			dp[i+1][max(x-j,0)] |= dp[i][j];
			dp[i+1][j] |= dp[i][j];
		}
		sum += x;
	}

	scanf("%d", &M);
	for (int i=0; i<M; i++) {
		int x; scanf("%d", &x);
		printf("%c ", dp[N][x] ? 'Y':'N');
	}
	puts("");
	return 0;
}