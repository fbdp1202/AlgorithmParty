// baekjoon 2305 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=42;

int N, K;
int dp[MAX_N];
int fibo[MAX_N];

int main() {
	scanf("%d%d", &N, &K);
	fibo[0] = fibo[1] = 1;
	for (int i=2; i<=41; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];

	dp[1] = 0; dp[2] = 2; dp[3] = 6;
	for (int i=4; i<=41; i++) {
		dp[i] = dp[i-1] + dp[i-2];
		for (int j=i-1; j>0; j--) {
			dp[i] += fibo[j];
		}
	}

	int L = K-1, R = N-K;
	int ret = dp[L+1] * fibo[R] + fibo[L] * dp[R+1];
	if (L && R) ret -= fibo[L]*fibo[R];
	printf("%d\n", ret);
	return 0;
}