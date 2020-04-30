// baekjoon 11500 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int t = 0;
		int x = 0;
		scanf("%d", &t);
		long long mul = 1;
		long long ret = 0;
		scanf("%lld", &ret);
		for (int i=0; i<t; i++) {
			mul *= t;
			scanf("%d", &x);
			ret += x*t;
		}
		printf("%lld\n", ret);
	}
	return 0;
}