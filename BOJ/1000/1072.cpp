// baekjoon 1072 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAX_INF = (1LL<<55);

ll X, Y, ret=MAX_INF;

inline int getScore(ll x, ll y) { return ((100LL*y)/x); }

int main()
{
	scanf("%lld%lld", &X, &Y);
	int cur = getScore(X, Y);

	ll left=0, right=MAX_INF;
	while (left <= right) {
		ll mid = (left + right)/2;
		if (cur < getScore(X + mid, Y + mid)) {
			ret = min(ret, mid);
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	if (ret == MAX_INF) {
		printf("-1\n");
	} else {
		printf("%d\n", ret);
	}

	return 0;
}