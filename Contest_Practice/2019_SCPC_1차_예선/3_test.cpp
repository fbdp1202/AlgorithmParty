#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int T;
ll x, y;

ll find(ll x, ll y, ll value, ll inc, ll cnt) {
	ll ret = 0;
	if (x <= value) ret = cnt;
	if (value + inc <= y) {
		if (value + inc + inc + 1 >= y) ret = max(ret, find(x, min(y, value + inc - 1), value + 1, 2, cnt+1));
		ret = max(ret, find(x, y, value + inc, inc+1, cnt+1));
	} else if (value + 1 <= y) {
		ret = max(ret, find(x, y, value + 1, 2, cnt+1));
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int t=0; t<=T; t++) {
		printf("Case #%d\n", t);
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", find(t, t, 0, 1, 0));
	}
	puts("");
	for (int t=0; t<=T; t++) {
		printf("Case #%d\n", t);
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", find(0, t, 0, 1, 0));
	}
	return 0;
}