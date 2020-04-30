#include <cstdio>
#include <algorithm>
using namespace std;

long long N, cnt, tmp, rnd, rndN;

int main() {
	scanf("%lld", &N);
	tmp=N;
	rnd=rndN=1LL;
	while (tmp/10LL) {
		cnt+=(rnd*9LL*rndN);
		rnd*=10LL;
		tmp/=10LL;
		rndN++;
	}
	cnt+=(N-rnd+1LL)*rndN;
	printf("%lld\n", cnt);
	return 0;
}