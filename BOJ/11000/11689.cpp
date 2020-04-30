// baekjoon 11689 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N=100001;

typedef long long ll;
ll N;
ll ret;

bool isprime[MAX_N];

int main() {
	scanf("%lld", &N);
	double ret = N;
	for (ll i=2; i*i<=N; i++) {
		if (N % i == 0) {
			while (N % i == 0 && N != 1) N /= i;
			ret *= (1.f - (1.f/(double)i));
		}
	}
	if (N > 1) {
		ret *= (1.f - (1.f/(double)N));
	}
	printf("%lld\n", (ll)ret);
	return 0;
}