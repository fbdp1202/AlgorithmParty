// baekjoon 8984 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<ll, ll> P;
const int MAX_N=100001;

int N, L;
P lines[MAX_N];
PP ulines[MAX_N], dlines[MAX_N];
ll t, d, dp[MAX_N], ans;
bool visited[MAX_N];

static inline ll dist(P &a) {
	return abs(a.first - a.second) + L;
}

int main() {
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++) {
		scanf("%lld %lld", &t, &d)
		lines[i].first = ulines[i].first.first = dlines[i].first.second = t;
		lines[i].second = ulines[i].first.second = dlines[i].first.first = d;
		ulines[i].second = dlines[i].second = i;
	}

	sort(ulines, ulines+N);
	sort(dlines, dlines+N);

	for (int i=0; i<N; i++) {
		ll length = dist(lines[i]);
		ll &ret = dp[i];
		ret = length;
		for (int j=0; j<i; j++) {
			if (lines[i].first == lines[j].first)
				ret = max(ret, dp[j]+length);
			if (lines[i].second == lines[j].second)
				ret = max(ret, dp[j]+length);
		}
		ans = max(ans, ret);
	}
	printf("%lld\n", ans);

	return 0;
}