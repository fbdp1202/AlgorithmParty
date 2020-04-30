// baekjoon 16282 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N;

ll getChain(int n) {
	ll ret = n;
	for (int t=0; t<=n; t++)
		ret += (n+1)*(1LL<<t);
	return ret;
}

int main()
{
	scanf("%lld", &N);
	for (int i=0; i<=56; i++)
		if (N <= getChain(i))
			return !printf("%d\n", i);

	return 0;
}