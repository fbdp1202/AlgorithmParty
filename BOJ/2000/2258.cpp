// baekjoon 2258 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N=100001;
const ll MAX_INF=(1LL<<62);

ll N, M;
pair<ll, ll> gogi[MAX_N];

int main()
{
	scanf("%lld%lld", &N, &M);
	for (int i=1; i<=N; i++) {
		scanf("%lld%lld", &gogi[i].second, &gogi[i].first);
		gogi[i].second *= -1;
	}
	sort(gogi+1, gogi+N+1);

	ll num = 0, cost = 0, ret=MAX_INF;
	for (int i=1; i<=N; i++) {
		num -= gogi[i].second;
		if (gogi[i].first == gogi[i-1].first) cost += gogi[i-1].first;
		else cost = 0;
		if (num >= M) ret = min(ret, cost+gogi[i].first);
	}
	if (num < M) {
		printf("-1\n");
	} else {
		printf("%lld\n", ret);
	}
	return 0;
}