// baekjoon 1750 yechan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N=101;
const int MAX_V=100001;
const int DIV_NUM=10000003;

int N, arr[MAX_N];
int pow2N[MAX_N];
int dp[MAX_N][MAX_V];

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int dfs(int here, int g=0) {
	if (g == 1) return pow2N[N-here];
	int &ret = dp[here][g];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=here+1; i<=N; i++)
		ret = (ret + dfs(i, gcd(arr[i], g)))%DIV_NUM;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	pow2N[0]=1;
	for (int i=1; i<=N; i++)
		pow2N[i] = (pow2N[i-1]*2)%DIV_NUM;

	for (int i=1; i<=N; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", dfs(0));
	return 0;
}