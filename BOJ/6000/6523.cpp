// baekjoon 6523 yechan
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, a, b;

int main()
{
	while (1)
	{
		scanf("%lld", &N);
		if (!N) break;
		scanf("%lld%lld", &a, &b);
		map<ll, int> m;
		ll now = 0;
		int num = 1;
		while (1) {
			now = (((a*now)%N)*now+b)%N;
			if (m[now]) {
				num -= m[now];
				break;
			}
			m[now]=num++;
		}
		printf("%lld\n", N-num);
	}
	return 0;
}