#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;
const int MAX_V=500001;

int N, block[MAX_N], dp[MAX_N][MAX_V];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &block[i]);

	for (int i=0; i<=N; i++)
		fill(dp[i],dp[i]+MAX_V, -1);

	int max_h=0;
	dp[0][0]=0;
	for (int i=0; i<N; i++) {
		int b = block[i];
		for (int j=0; j<=max_h; j++) {
			if (dp[i][j] == -1) continue;
			dp[i+1][j+b] = max(dp[i+1][j+b], dp[i][j] + b); // 높은 쪽에 쌓는 경우
			dp[i+1][abs(j-b)] = max(dp[i+1][abs(j-b)], dp[i][j] + max(0, b-j)); // 낮은 쪽에 쌓는 경우
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]); // 안 쌓는 경우
		}
		max_h += b;
	}
	printf("%d\n", dp[N][0]==0 ? -1 : dp[N][0]);
	return 0;
}