// baekjoon 2410 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=1000001;
const ll DIV_NUM=1000000000;

int N;
ll dp[MAX_N];

int main() {
	scanf("%d", &N);
	dp[1] = 1;
	for (int i=2; i<=N; i++)
		dp[i] = (dp[i-1] + ((i%2) ? 0 : dp[i/2]))%DIV_NUM;
	printf("%lld\n", dp[N]);
	return 0;
}