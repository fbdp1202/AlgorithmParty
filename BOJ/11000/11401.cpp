// baekjoon 11401 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int DIV_NUM=1000000007;

int N, K;

ll factorial(ll n) {
	if (n == 1) return 1;
	if (n == 0) return 1;
	return (n*factorial(n-1))%DIV_NUM;
}

ll powMe(ll n, ll k) {
	if (k == 0) return 1;
	ll ret = powMe(n, k/2);
	ret = (ret * ret) % DIV_NUM;
	if (k % 2 == 1) ret = (ret * n) % DIV_NUM;
	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	ll a = factorial(N) % DIV_NUM;
	ll b = (factorial(K)*factorial(N-K)) % DIV_NUM;
	printf("%lld\n", (a*powMe(b,DIV_NUM-2)%DIV_NUM));
	return 0;
}