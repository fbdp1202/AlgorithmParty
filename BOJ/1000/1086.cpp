// baekjoon 1086 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N=15;
const int MAX_SIZE=(1<<15);
const int MAX_K=101;

int N, K;
int numlen[15];
int num[15];
int ppow10[52];
char str[15][52];
ll dp[MAX_SIZE][MAX_K];

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

ll factorial(ll n) {
	ll val = 1;
	while (n) {
		val *= (n--);
	}
	return val;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%s", str[i]);
		numlen[i] = (int)strlen(str[i]);
	}

	scanf("%d", &K);
	ppow10[0]=1;
	for (int i=1; i<52; i++)
		ppow10[i] = (ppow10[i-1]*10)%K;

	for (int i=0; i<N; i++)
		for (int j=0; str[i][j]; j++)
			num[i] = (num[i] * 10 + (str[i][j] - '0')) % K;

	dp[0][0]=1;
	for (int bitmask=0; bitmask<(1<<N)-1; bitmask++) {
		for (int bit0=0; bit0<N; bit0++) {
			if (bitmask & (1 << bit0)) continue;
			for (int r=0; r<K; r++) {
				if (dp[bitmask][r] == 0) continue;
				int r_new = (num[bit0] + r * ppow10[numlen[bit0]]) % K;
				dp[bitmask | (1 << bit0)][r_new] += dp[bitmask][r];
			}
		}
	}

	ll p = dp[(1<<N)-1][0];
	ll q = factorial(N);
	ll g = gcd(p, q);
	printf("%lld/%lld\n", p/g, q/g);
	return 0;
}