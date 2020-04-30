// baekjoon 1850 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int T;
ll a, b;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld %lld", &a, &b);

		ll result = a*b;
		while (b!=0){
			ll r = a%b;
			a=b;
			b=r;
		}
		printf("%lld\n", result/a);
	}
	return 0;
}