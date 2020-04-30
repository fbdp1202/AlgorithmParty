// baekjoon 4233 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll p, a;
bool isPrime(ll p) {
	for (int i=2; i*i <= p; i++)
		if (p % i == 0) return false;
	return true;
}

ll pow(ll a, ll b){
	if (b == 0) return 1;
	if (b == 1) return a;
	ll ret = pow(a, b/2) % p;
	ret = (ret * ret) % p;
	if (b % 2 == 1) ret = (ret * a) % p;
	return ret;
}

int main() {
	while (scanf("%lld%lld",&p,&a)) {
		if (!p && !a) break;
		ll ret = pow(a, p);
		if (!isPrime(p) && ret == a) {
			puts("yes");
		} else {
			puts("no");
		}
	}
	return 0;
}