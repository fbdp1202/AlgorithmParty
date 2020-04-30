// baekjoon 8984 yechan
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<pair<ll,ll>, ll> PP;

int N, L, t, d;
P points[MAX_N];
PP pointup[MAX_N], pointdown[MAX_N];
ll dp[MAX_N][2]; // state : (0 up, 1 down)
ll ans=0;
bool visited[MAX_N][2];


static inline ll dist(P &a) { return abs(a.first - a.second) + L; }

ll dfsDown(int uppos, int downpos);

ll dfsUp(int uppos, int downpos) { // state 0
	int idx = pointup[uppos].second;
	ll &ret = dp[idx][0];
	visited[idx][0]=true;
	if (ret != -1) return ret;
	ll upValue = points[idx].first;
	ll downValue = points[idx].second;
	ll length = dist(points[idx]);
	ret = length;
	downpos = lower_bound(pointdown, pointdown+N, PP(P(upValue, -1), -1)) - pointdown;
	while (downpos < N && points[pointdown[downpos].second].first == upValue) {
		if (pointdown[downpos].second != idx && points[pointdown[downpos].second].second > downValue)
			ret = max(ret, length + dfsDown(uppos, downpos));
		downpos++;
	}
	return ret;
}

ll dfsDown(int uppos, int downpos) { // state 1
	int idx = pointdown[downpos].second;
	ll &ret = dp[idx][1];
	visited[idx][1]=true;
	if (ret != -1) return ret;
	ll upValue = points[idx].first;
	ll downValue = points[idx].second;
	ll length = dist(points[idx]);
	ret = length;
	uppos = lower_bound(pointup, pointup+N, PP(P(downValue, -1), -1)) - pointup;
	while (uppos < N && points[pointup[uppos].second].second == downValue) {
		if (pointup[uppos].second != idx && points[pointup[uppos].second].first > upValue)
			ret = max(ret, length + dfsUp(uppos, downpos));
		uppos++;
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &L);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &t, &d);
		points[i].first = t;
		points[i].second = d;
		pointup[i].first.first = d;
		pointup[i].first.second = t;
		pointup[i].second = i;
		pointdown[i].first.first = t;
		pointdown[i].first.second = d;
		pointdown[i].second = i;
	}

	sort(pointup, pointup+N);
	sort(pointdown, pointdown+N);

	for (int i=0; i<N; i++) {
		if (!visited[pointup[i].second][0])
			ans = max(ans, dfsUp(i, 0));
		if (!visited[pointdown[i].second][1])
			ans = max(ans, dfsDown(0, i));
	}
	printf("%lld\n", ans);
	return 0;
}