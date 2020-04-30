// baekjoon 1866 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=3001;

int N, T, H, A[MAX_N], dp[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &A[i]);
	sort(A+1, A+N+1);
	scanf("%d%d", &T, &H);

	for (int i=1; i<=N; i++) {
		dp[i] = dp[i-1] + A[i]*T;
		// j~i 중앙에 비행기 + 트럭 업데이트
		int cost = H;
		for (int j=i; j>0; j--) {
			cost += (A[(i+j+1)/2]-A[j])*T;
			dp[i] = min(dp[i], dp[j-1]+cost);
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}