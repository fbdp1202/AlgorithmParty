// baekjoon 1577 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=103;

int N, M, K;
ll dp[MAX_N][MAX_N];
bool U[MAX_N][MAX_N];
bool L[MAX_N][MAX_N];

void check(int a, int b, int c, int d) {
	if (a == c) U[min(b,d)][a] = true;
	if (b == d) L[b][min(a,c)] = true;
}

int main() {
	scanf("%d%d", &N, &M);
	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a++,b++,c++,d++;
		check(a,b,c,d);
	}

	dp[0][1]=1;
	for (int i=1; i<=M+1; i++) {
		for (int j=1; j<=N+1; j++) {
			if (!L[i][j-1]) dp[i][j] += dp[i][j-1];
			if (!U[i-1][j]) dp[i][j] += dp[i-1][j];
		}
	}
	printf("%lld\n", dp[M+1][N+1]);

	return 0;
}