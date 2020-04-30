// baekjoon 1790 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, cnt, tmp, rnd, rndN, K;

int main() {
	scanf("%lld%lld", &N, &K);
	tmp=N;
	rnd=rndN=1LL;
	while (tmp/10LL) {
		if (K-cnt <= rnd*9LL*rndN) {
			ll num = (K-cnt+rndN-1)/rndN+rnd-1;
			ll pos = rndN-(K-cnt+rndN-1)%(rndN)-1;
			while (pos--) num/=10LL;
			return !printf("%lld\n", num%10LL);
		}
		cnt+=(rnd*9LL*rndN);
		rnd*=10LL;
		tmp/=10LL;
		rndN++;
	}
	if (K-cnt <= (N-rnd+1LL)*rndN) {
		ll num = (K-cnt+rndN-1)/rndN+rnd-1;
		ll pos = rndN-(K-cnt+rndN-1)%(rndN)-1;
		while (pos--) num/=10LL;
		return !printf("%lld\n", num%10LL);
	}
	return !printf("-1\n");
}